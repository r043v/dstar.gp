/***************************************************
		      dstar :D
***************************************************/

#include "Gdl.h"

#include ".\data\gfx\FONT16.h"
#include ".\data\gfx\etoile.h"

char * theme_path ;
char tmp_url[100] ;
uchar * yaya, yoyo ;
uint tiles_Pal[0xFF] ;
char first=1 ;
uchar * trou_noir ;
ulong tmp_size ;
uint cmpt, cmpt2, tmp_color ;
struct font font8, system_font ;
ushort * font_8_bmp ;

#include "dstar.h"
#include ".\gdl\dir.h"

void GpMain(void *arg)
{
	char * map_url = gm_malloc(100) ;
	short yop=0,yap=0 ;
	init_screen(16) ;
	GpFatInit() ;

	font_8_bmp = convert_8b_to_16b((uchar *)etoile,320,16,(uint*)HARDWARE_PALETTE) ;

	load_font(&system_font,(uchar *)font_8_bmp,16,16,HARDWARE_PALETTE[0xFD],64) ;
	set_system_font(&system_font) ;

	white_pal() ;

	GPSTRCPY(theme_path,"gp:\\gpmm\\dstar\\skin\\classic") ;
	GPSTRCPY(skin_url,"gp:\\gpmm\\dstar\\skin\\classic\\thm.pcx") ;

	charge_palette_pcx(skin_url,tiles_Pal) ;
	fade_to_palette(0,tiles_Pal) ;

	read_save_file() ;

	yaya = load_pcx(skin_url) ;

	GPSTRCPY(skin_url,theme_path) ;

	do {
		choose_map() ;

		GPSPRINTF(map_url,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;

		//_free(etoile) ;
		map_header = read_map_file_with_tile(&level,map_url,yaya) ;

		nb_star = 0 ;
		moving = 0 ;
		old_moving = 0 ;
		dye_count = 0 ;
		selected = 0 ;
		time = 0 ;
		move_number = 0 ;

		// search cursor, block tile and count star in the map
		for(cpt_x=0;cpt_x<20;cpt_x++)
			for(cpt_y=0;cpt_y<15;cpt_y++)
			{
				switch(level.map[cpt_y*level.size_x+cpt_x])
				{
					case 6 : // cursor

					cursor_pos_x = cpt_x * 16 ;
					cursor_pos_y = cpt_y * 16 ;

					level.map[cpt_y*level.size_x+cpt_x] = 0 ;

					break ;

					case 3 : // cursor block

					block_pos_x = cpt_x * 16 ;
					block_pos_y = cpt_y * 16 ;

					level.map[cpt_y*level.size_x+cpt_x] = 0 ;

					break ;

					case 7 : // star

					nb_star++ ;

					break ;

					case 4 : break ;

					//level.map[cpt_y*level.size_x+cpt_x] = 0 ;
				}
			} ;

		for(cpt=0;cpt<2;cpt++)
		{	for(cpt_x=0;cpt_x<20;cpt_x++)
				for(cpt_y=0;cpt_y<15;cpt_y++)
				{
					switch(level.map[cpt_y*20 + cpt_x])
					{
						case 0 : draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ; break ;

						case 7 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,7,cpt_x<<4,cpt_y<<4) ;
						break ;

						case 1 : draw_tile_xy(&level,1,cpt_x<<4,cpt_y<<4) ; break ;
						case 2 : draw_tile_xy(&level,2,cpt_x<<4,cpt_y<<4) ; break ;

						case 4 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,4,cpt_x<<4,cpt_y<<4) ;
						break ;
					}
				} ;

			flip_screen() ;
		} ;

		do {
			refresh_key() ;

			for(cpt_x=0;cpt_x<20;cpt_x++)
				for(cpt_y=0;cpt_y<15;cpt_y++)
				{
					switch(level.map[cpt_y*20 + cpt_x])
					{
						case 0 : draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ; break ;

						case 7 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,7,cpt_x<<4,cpt_y<<4) ;
						break ;

						case 4 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,4,cpt_x<<4,cpt_y<<4) ;
						break ;
					}
				} ;

			//clr_scr() ;
			//draw_map_animated_16(&level) ;

			draw_tile_xy(&level,6,cursor_pos_x,cursor_pos_y) ;
			draw_tile_xy(&level,3,block_pos_x,block_pos_y) ;

			if(selected)	draw_tile_xy(&level,3,5,5) ;
			else		draw_tile_xy(&level,6,5,5) ;

			draw_int(&font8,count_fps(),40,5) ;
			timer_inc(&font8,&time,70,5) ;
			draw_int(&font8,move_number,100,5) ;

			if(!moving)
			{
				// gauche
				if(key_pressed&1) moving = 1 ;

				// droite
				if(key_pressed&4) moving = 4 ;

				// haut
				if(key_pressed&8) moving = 8 ;

				// bas
				if(key_pressed&2) moving = 2 ;

				if(up_front(32)) selected ^= 1 ;
				if(up_front(64)) selected ^= 1 ;
			}
			else
			{
				char tile, move=0 ;

				switch(moving)
				{
					case 1 : // gauche
						switch(selected)
						{
							case 0 :

							tile = get_tile(&level,cursor_pos_x-1,cursor_pos_y+8) ;
							if(tile == 7) set_tile(&level,cursor_pos_x-1,cursor_pos_y+8,0) ;
							if(tile == 7) nb_star-- ;

							if(cursor_pos_y != block_pos_y)  move=1 ;
							else	if(cursor_pos_x != block_pos_x+16) move=1 ;

							if(move)
							{
								if((!tile)||(tile==7)) cursor_pos_x-=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;

							case 1 :

							tile = get_tile(&level,block_pos_x-1,block_pos_y+8) ;

							if(block_pos_y != cursor_pos_y)  move=1 ;
							else	if(block_pos_x != cursor_pos_x+16) move=1 ;

							if(move)
							{
								if(!tile) block_pos_x-=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;
						}

					break ;

					case 4 : // droite
						switch(selected)
						{
							case 0 :

							tile = get_tile(&level,cursor_pos_x+17,cursor_pos_y+8) ;
							if(tile == 7) set_tile(&level,cursor_pos_x+17,cursor_pos_y+8,0) ;
							if(tile == 7) nb_star-- ;

							if(cursor_pos_y != block_pos_y) move=1 ;
							else	if(cursor_pos_x+16 != block_pos_x) move=1 ;

							if(move)
							{
								if((!tile)||(tile==7)) cursor_pos_x+=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;

							case 1 :

							tile = get_tile(&level,block_pos_x+17,block_pos_y+8) ;

							if(block_pos_y != cursor_pos_y) move=1 ;
							else	if(block_pos_x+16 != cursor_pos_x) move=1 ;

							if(move)
							{
								if(!tile) block_pos_x+=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;
						}

					break ;

					case 8 : // haut
						switch(selected)
						{
							case 0 :

							tile = get_tile(&level,cursor_pos_x+8,cursor_pos_y-1) ;
							if(tile == 7) set_tile(&level,cursor_pos_x+8,cursor_pos_y-1,0) ;
							if(tile == 7) nb_star-- ;

							if(cursor_pos_x != block_pos_x) move=1 ;
							else	if(cursor_pos_y != block_pos_y+16) move=1 ;

							if(move)
							{
								if((!tile)||(tile==7)) cursor_pos_y-=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;

							case 1 :

							tile = get_tile(&level,block_pos_x+8,block_pos_y-1) ;

							if(block_pos_x != cursor_pos_x) move=1 ;
							else	if(block_pos_y != cursor_pos_y+16) move=1 ;

							if(move)
							{
								if(!tile) block_pos_y-=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;
						}


					break ;

					case 2 : // bas
						switch(selected)
						{
							case 0 :

							tile = get_tile(&level,cursor_pos_x+8,cursor_pos_y+17) ;
							if(tile == 7) set_tile(&level,cursor_pos_x+8,cursor_pos_y+17,0) ;
							if(tile == 7) nb_star-- ;

							if(cursor_pos_x != block_pos_x) move=1 ;
							else	if(cursor_pos_y+16 != block_pos_y) move=1 ;

							if(move)
							{
								if((!tile)||(tile==7)) cursor_pos_y+=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;

							case 1 :

							tile = get_tile(&level,block_pos_x+8,block_pos_y+17) ;

							if(block_pos_x != cursor_pos_x) move=1 ;
							else	if(block_pos_y+16 != cursor_pos_y) move=1 ;

							if(move)
							{
								if(!tile) block_pos_y+=8 ;
								else moving = 0 ;
							} else moving = 0 ;

							break ;
						}

					break ;
				}

				if((!moving)&&(old_moving)) move_number++ ;

				old_moving=moving ;
			}

			flip_screen() ;

			if(!nb_star) dye_count++ ;

		} while((!instant_key(512))&&(dye_count<10)) ;

		if(dye_count==10)
		{
			char buf[30] ;

			if((move_number < pz_save[curent_map_number].nb_moves)||(!pz_save[curent_map_number].nb_moves)) // new record :D
			{
				short number = pz_save[curent_map_number].nb_moves - move_number ;
				pz_save[curent_map_number].nb_moves = move_number ;
				pz_save[curent_map_number].time = time ;
				//write_save_file() ;

				if(number>1)	GPSPRINTF(buf,"move record :D\n-%i moves",number);
				else	if(number)	GPSTRCPY(buf,"move record :D\n- 1 move");

				draw_text_center(&font8, buf) ;
				flip_screen() ;
				draw_text_center(&font8, buf) ;
				flip_screen() ;

				wait_key(256) ;
			}
			else
			{
				if(move_number == pz_save[curent_map_number].nb_moves) // equal move record, test time :)
					if(time < pz_save[curent_map_number].time)
					{
						short number = pz_save[curent_map_number].time - time ;
						pz_save[curent_map_number].time = time ;
						//write_save_file() ;

						if(time < pz_save[curent_map_number].time!=0)
						{
							if(number>1)	GPSPRINTF(buf,"time record :D\n -%isec.",number);
							else		GPSTRCPY(buf,"time record :D\n-1 sec.");

							draw_text_center(&font8, buf) ;
							flip_screen() ;
							draw_text_center(&font8, buf) ;
							flip_screen() ;
							wait_key(256) ;
						}
					}
			}
		}

		free_map(&map_header) ;

	} while(1) ;
}
