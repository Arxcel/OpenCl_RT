/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:30:30 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/03 17:28:19 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char *get_file_content(const char *filename, int *file_size)
{
	struct stat	filestatus;
	int			fd;
	char		*file_contents;

	if ((stat(filename, &filestatus) != 0) || !(S_ISREG(filestatus.st_mode)))
		put_error("File not found.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		put_error("Error opening the file.");
	*file_size = filestatus.st_size;
	file_contents = (char*)malloc(filestatus.st_size + 1);
	if (file_contents == NULL)
		put_error("Memory error: unable to allocate.");
	if (read(fd, file_contents, filestatus.st_size + 1) < 0) {
		close(fd);
		free(file_contents);
		put_error("Error reading the file.");
	}
	close(fd);
	file_contents[filestatus.st_size] = '\0';
	return (file_contents);
}

static int	set_o_type(json_value* value)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "plane"))
		val = O_PLANE;
	else if (!err && !ft_strcmp(value->u.string.ptr, "sphere"))
		val = O_SPHERE;
	else if (!err && !ft_strcmp(value->u.string.ptr, "cylinder"))
		val = O_CYL;
	else if (!err && !ft_strcmp(value->u.string.ptr, "conus"))
		val = O_CON;
	else
		err = 1;
	if (err)
		put_error("Not valid object type");
	return (val);
}

static int	set_l_type(json_value* value)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "sun"))
	{
		val = L_SUN;

	}
	else
		err = 1;
	if (err)
		put_error("Not valid light type");
	return (val);
}

static int	set_c_type(json_value* value)
{
	int err;
	int val;

	err = 0;
	val = -1;
	if (value->type != json_string)
		err = 1;
	if (!err && !ft_strcmp(value->u.string.ptr, "common"))
		val = 1;
	else
		err = 1;
	if (err)
		put_error("Not valid camera type");
	return (val);
}

static float get_number(json_value* value)
{
	float ret;

	ret = 0;
	if (value->type == json_integer)
		ret = (float)value->u.integer;
	else if (value->type == json_double)
		ret = (float)value->u.dbl;
	else
		put_error("Not a number format where expected.");
	return ret;
}
static t_vector get_vector(json_value* value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for vector.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length.");
	x = -1;
	while (++x < length)
		v[x] = get_number(value->u.array.values[x]);
	return (v);
}

static t_vector get_n_vector(json_value* value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for object direction.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length for object direction.");
	x = -1;
	while (++x < length)
		v[x] = get_number(value->u.array.values[x]);
	v = v_normalize(v);
	return (v);
}

static t_vector get_color(json_value* value)
{
	t_vector	v;
	int			length;
	int			x;

	v = (t_vector){0, 0, 0};
	if (value == NULL)
		put_error("No value for vector.");
	if ((length = value->u.array.length) != 3)
		put_error("Wrong vector length.");
	x = -1;
	while (++x < length)
	{
		v[x] = get_number(value->u.array.values[x]);
		if (v[x] > 1 || v[x] < 0)
			put_error("The color intensity can not be more than 1 or less than 0.");

	}	
	return (v);
}

static void get_object_info(json_value* value, t_object *o)
{
	int length;
	int x;

	if (value == NULL)
		return;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "type"))
			o->type = set_o_type(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "direction"))
			o->dir = get_n_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "point"))
			o->point = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "color"))
			o->color = get_color(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "radius"))
			o->radius = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "shape"))
			o->shape = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "angle"))
			o->angle = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "distance"))
			o->p = get_number(value->u.object.values[x].value);
	}
}

static void process_scene_o(json_value* value, t_scene *s)
{
	int x;

	s->o_num = value->u.object.length + 1;
	s->object = (t_object*)ft_memalloc(sizeof(t_object) * s->o_num);
	ft_bzero(s->object, sizeof(s->object));
	x = -1;
	while (++x < s->o_num - 1)
		get_object_info(value->u.array.values[x], &s->object[x]);
	s->object[x].type = 0;
}

static void get_light_info(json_value* value, t_light *l)
{
	int length;
	int x;

	if (value == NULL)
		return;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "type"))
			l->type = set_l_type(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "position"))
			l->pos = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "color"))
			l->color = get_color(value->u.object.values[x].value);
	}
}

static void process_scene_l(json_value* value, t_scene *s)
{
	int x;

	s->l_num = value->u.object.length + 1;
	s->light = (t_light*)ft_memalloc(sizeof(t_light) * s->l_num);
	ft_bzero(s->light, sizeof(s->light));
	x = -1;
	while (++x < s->l_num - 1)
		get_light_info(value->u.array.values[x], &s->light[x]);
	s->light[x].type = 0;

}

static void get_camera_info(json_value* value, t_camera *c)
{
	int length;
	int x;

	if (value == NULL)
		return;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "type"))
			c->type = set_c_type(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "position"))
			c->pos = get_vector(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "field_of_view"))
			c->fov = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "bias"))
			c->bias = get_number(value->u.object.values[x].value);
		if (!ft_strcmp(value->u.object.values[x].name, "rotation"))
			c->rot = get_vector(value->u.object.values[x].value);
	}
}

static void process_scene_c(json_value* value, t_scene *s)
{
	int x;

	s->c_num = value->u.object.length + 1;
	s->camera = (t_camera*)ft_memalloc(sizeof(t_camera) * s->c_num);
	ft_bzero(s->camera, sizeof(s->camera));
	x = -1;
	while (++x < s->c_num - 1)
		get_camera_info(value->u.array.values[x], &s->camera[x]);
	s->camera[x].type = 0;
}

static void process_object(json_value* value, t_scene *s)
{
	int length;
	int x;

	if (value == NULL)
		return;
	length = value->u.object.length;
	x = -1;
	while (++x < length)
	{
		if (!ft_strcmp(value->u.object.values[x].name, "objects"))
			process_scene_o(value->u.object.values[x].value, s);
		if (!ft_strcmp(value->u.object.values[x].name, "lights"))
			process_scene_l(value->u.object.values[x].value, s);
		if (!ft_strcmp(value->u.object.values[x].name, "cameras"))
			process_scene_c(value->u.object.values[x].value, s);
	}
}

void	process_value(json_value* value, t_scene *s)
{
	if (value == NULL) 
		return ;
	if (value->type == json_none)
		ft_printf("none");
	else if (value->type == json_object)
		process_object(value, s);
	else if (value->type == json_array)
		put_error("Unexpected array.");
	else if (value->type == json_integer)
		put_error("Unexpected integer.");
	else if (value->type == json_double)
		put_error("Unexpected double.");
	else if (value->type == json_string)
		put_error("Unexpected string.");
	else if (value->type == json_boolean)
		put_error("Unexpected boolean.");
}

void	get_scene(const char *filename, t_scene *s)
{
	json_char*	json;
	json_value*	value;
	int			file_size;
	char		*file_str;

	if (ft_strcmp(".rt", (char*)(filename + ft_strlen(filename) - 3)))
		put_error("Wrong file format. Please choose file *.rt");
	ft_bzero(s, sizeof(s));
	file_str = get_file_content(filename, &file_size);
	json = (json_char*)file_str;
	value = json_parse(json, file_size);
	if (value == NULL)
	{
		free(file_str);
		put_error("Unable to parse data");
	}
	process_value(value, s);
	json_value_free(value);
	free(file_str);
}