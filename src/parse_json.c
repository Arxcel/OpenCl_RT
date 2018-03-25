/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_json.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:33:17 by vkozlov           #+#    #+#             */
/*   Updated: 2018/03/25 16:24:41 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rt.h"

static char		*get_file_content(const char *filename, int *file_size)
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
	if (read(fd, file_contents, filestatus.st_size + 1) < 0)
	{
		close(fd);
		free(file_contents);
		put_error("Error reading the file.");
	}
	close(fd);
	file_contents[filestatus.st_size] = '\0';
	return (file_contents);
}

static void		process_object(json_value *value, t_scene *s)
{
	int length;
	int x;

	if (value == NULL)
		return ;
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

void			process_value(json_value *value, t_scene *s)
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

void			get_scene(const char *filename, t_scene *s)
{
	json_char	*json;
	json_value	*value;
	int			file_size;
	char		*file_str;

	if (ft_strcmp(".json", (char*)(filename + ft_strlen(filename) - 5)))
		put_error("Wrong file format. Please choose file *.json");
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
