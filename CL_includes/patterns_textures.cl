
static float get_pattern2(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;

    scale = (float)o->t_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE)
    {
        scaleX = scale * 25;
        scaleY = scale * 25;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = scale / 50;
        scaleY = scale / 50;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = scale * 0.05;
        scaleY = scale * 10;
    }
	return (((sin(M_PI * r->tex[1] / scaleY)) > 0) ^ ((sin(M_PI * r->tex[0] / scaleX) > 0)));
}

static float get_pattern3(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;

    scale = (float)o->t_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE)
    {
        scaleX = scale * 50;
        scaleY = scale * 50;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = scale / 25;
        scaleY = scale / 25;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = scale * 0.1;
        scaleY = scale * 20;
    }
	return ((sin(M_PI * r->tex[0] / scaleX) > 0 ? sin(M_PI * r->tex[0] / scaleX) : -sin(M_PI * r->tex[0] / scaleX)));
}


static float get_pattern4(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;

    scale = (float)o->t_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE)
    {
        scaleX = scale * 50;
        scaleY = scale * 50;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = scale / 25;
        scaleY = scale / 25;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = scale * 0.1;
        scaleY = scale * 20;
    }
	return ((sin(M_PI * r->tex[1] / scaleY) > 0 ? sin(M_PI * r->tex[1] / scaleY) : -sin(M_PI * r->tex[1] / scaleY)));
}

static float get_pattern5(t_ray *r, t_object *o)
{
    float   scale;
    float   pattern;

    scale = (float)o->t_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE)
    {
        scale *= 0.015;
    }
    else if (o->type == O_SPHERE)
    {
        scale *= 50;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scale *= 0.1;
    }
    pattern = sin(sqrt(r->tex[0] * r->tex[0] + r->tex[1] * r->tex[1]) * scale);
	return (pattern > 0 ? pattern : -pattern);
}

t_vector			get_object_color(t_object *o, t_ray *r, unsigned int *seed1, unsigned int *seed2)
{
    float pattern;

    pattern = 0;
    if (o->t_id == T_CHECK)
	    pattern = get_pattern2(r, o);
    else if (o->t_id == T_GRAD1)
        pattern = get_pattern3(r, o);
    else if (o->t_id == T_GRAD2)
        pattern = get_pattern4(r, o);
    else if (o->t_id == T_CIRC)
        pattern = get_pattern5(r, o);
    return (v_mult_d(o->color, 0.5 * pattern) + v_mult_d(o->color, 0.5));
}