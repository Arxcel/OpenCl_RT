
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

t_vector			get_object_color(t_object *o, t_ray *r)
{
    if (o->t_id)
	    return (v_mult_d(o->color, 0.5 * get_pattern2(r, o)) + v_mult_d(o->color, 0.5));
    else
        return (o->color);
}