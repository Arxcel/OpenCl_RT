
static float get_pattern(t_ray *r)
{
    // r->tex = m_mult_v33(v_rot2(90), r->tex);
	return ((sin(M_PI * r->tex[1] / 5)) > 0 ^ (sin(M_PI * r->tex[0] / 5) > 0));
}

t_vector			get_object_color(t_object *o, t_ray *r)
{
    // if (o->permutation_id)
	//     return (v_mult_d(o->color, get_pattern(r)));
    // else
        return (o->color);
}