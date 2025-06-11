
#include "../includes/cub.h"

void	draw_map(t_map *m, t_minimap *mi, t_player *p)
{
	mi->start_x = p->pos_x - mi->size;
	mi->start_y = p->pos_y - mi->size;
	mi->end_x = p->pos_x + mi->size;
	mi->end_y = p->pos_y + mi->size;
	if(m->m_height > 10 || m->m_width > 10)
	{
		draw_big_map(m, mi);
		draw_big_player(mi, p);
		draw_big_rays(m, mi, p);
	}
	else
	{
		draw_small_map(m);
		draw_small_player(p);
		draw_small_rays(m, mi, p);
	}
}
