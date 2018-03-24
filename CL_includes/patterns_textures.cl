
static float get_pattern2(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;
    float first;
    float second;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
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
    first = (M_PI * r->tex[1] / scaleY);
    second = (M_PI * r->tex[0] / scaleX);
	return (((native_sin(first)) > 0) ^ ((native_sin(second) > 0)));
}

static float get_pattern3(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;
    float first;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
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
    first = (M_PI * r->tex[0] / scaleX);
	return (native_sin(first) > 0 ? native_sin(first) : -native_sin(first));
}


static float get_pattern4(t_ray *r, t_object *o)
{
    float scale;
    float scaleX;
    float scaleY;
    float first;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
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
    first = M_PI * r->tex[1] / scaleY;
	return ((native_sin(first) > 0 ? native_sin(first) : -native_sin(first)));
}

static float get_pattern5(t_ray *r, t_object *o)
{
    float   scale;
    float   pattern;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
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
    pattern = r->tex[0] * r->tex[0] + r->tex[1] * r->tex[1];
    pattern = native_sqrt(pattern) * scale;
    pattern = native_sin(pattern);
	return (pattern > 0 ? pattern : -pattern);
}

static float get_pattern6(t_ray *r, t_object *o)
{
    float   scale;
    float   scaleX;
    float   scaleY;
    float   texX;
    float   texY;
    int     tx;
    int     ty;
    int     oddity;
    int     edge;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
    {
        scaleX = scale * 0.02;
        scaleY = scale * 0.02;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = scale * 15;
        scaleY = scale * 15;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = 10;
        scaleY = 0.05;
    }
    texX =  r->tex[0] * scaleX;
    texY =  r->tex[1] * scaleY;
    tx = (int)(texX);
    ty = (int)(texY);
    oddity = (tx & 0x1) == (ty & 0x1);
    texX = texX - tx;
    texY = texY - ty;
    texX = texX < 0 ? -texX : texX;
    texY = texY < 0 ? -texY : texY;
    edge = ((texX < 0.1) && oddity) || (texY < 0.1);
	return (edge ? 0 : 1);
}

static t_vector     get_custom(t_ray *r, t_object *o, global unsigned int *tex1)
{
    float scale;
    float scaleX;
    float scaleY;
    int     texX;
    int     texY;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
    {
        scaleX = 0.03 / scale;
        scaleY = 0.03 / scale;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = 5 / scale;
        scaleY = 5 / scale;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = 5 / scale;
        scaleY = 0.03 / scale;
    }
    texX = (int)(r->tex[0] * 256 * scaleX);
    texY = (int)(r->tex[1] * 256 * scaleY);
    texX = texX < 0 ? -texX : texX;
    texY = texY < 0 ? -texY : texY;
    return (get_rgb(tex1[texX % 256 + texY % 256 * 256]));
}

static t_vector     get_perlin(t_ray *r, t_object *o, global unsigned int *perlin)
{
    float scale;
    float scaleX;
    float scaleY;
    int     texX;
    int     texY;

    r->tex = m_mult_v33(v_rot2(o->tex_angle), r->tex);
    scale = (float)o->tex_scale;
    if (!scale)
        scale = 1.0;
    if (o->type == O_PLANE || o->type == O_DISK || o->type == O_TRIANGLE || o->type == O_SQUARE)
    {
        scaleX = 0.03 / scale;
        scaleY = 0.03 / scale;
    }
    else if (o->type == O_SPHERE)
    {
        scaleX = 5 / scale;
        scaleY = 5 / scale;
    }
    else if (o->type == O_CYL || o->type == O_PARABOLOID || o->type == O_CON)
    {
        scaleX = 5 / scale;
        scaleY = 0.03 / scale;
    }
    texX = (int)(r->tex[0] * 256 * scaleX);
    texY = (int)(r->tex[1] * 256 * scaleY);
    texX = texX < 0 ? -texX : texX;
    texY = texY < 0 ? -texY : texY;
    return (get_rgb(perlin[texX % 256 + texY % 256 * 256]));
}

t_vector			get_object_color(t_object *o,
                                        t_ray *r,
                                        global unsigned int *tex1,
                                        global unsigned int *tex2,
                                        global unsigned int *tex3,
                                        global unsigned int *tex4,
                                        global unsigned int *perlin)
{
    float pattern;

    pattern = 0;
    if (o->tex_id == T_STD)
        return (o->color);
    else if (o->tex_id == T_CHECK)
	    pattern = get_pattern2(r, o);
    else if (o->tex_id == T_GRAD1)
        pattern = get_pattern3(r, o);
    else if (o->tex_id == T_GRAD2)
       return (get_perlin(r, o, perlin));
    else if (o->tex_id == T_CIRC)
        pattern = get_pattern5(r, o);
    else if (o->tex_id == T_BRICK)
        pattern = get_pattern6(r, o);
    else if (o->tex_id == T_CUSTOM1)
        return (get_custom(r, o, tex1));
    else if (o->tex_id == T_CUSTOM2)
        return (get_custom(r, o, tex2));
    else if (o->tex_id == T_CUSTOM3)
        return (get_custom(r, o, tex3));
    else if (o->tex_id == T_CUSTOM4)
        return (get_custom(r, o, tex4));
    return (v_mult_d(o->color, 0.5 * pattern) + v_mult_d(o->color, 0.5));
}
