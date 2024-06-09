void	allocate_line(t_vars *vars, t_point g_pos)
{
	vars->map.grid[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(char));
	vars->map.tiles[g_pos.px_y] = malloc((vars->map.g_w - 1) * sizeof(t_tile));
}