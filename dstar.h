
char buffer[70] ;

GPDIRENTRY liste_des_map[256] ;
ulong nombre_de_map=0 ;
short map_selected = 2 ;

struct map_header map_header ;
struct map level ;

struct map fonte, fontch ;

short tile_value_A=1,cpt ;
struct gfx curseur ;
short tile_draw_x = 296 ;
short startx, starty ;

unsigned short cpt_x, cpt_y, nb_star, moving, old_moving ;

struct map level ;


short cursor_pos_x, cursor_pos_y ;
short block_pos_x, block_pos_y ;

char dye_count=0 ;

char selected = 0 ; // 0 : cursor   1 : block

uint time = 0 ;
ushort move_number = 0 ;

ushort curent_map_number ;
char tmp_buf[3] ;


char skin_url[50] ;

/*unsigned int tiles_Pal[256] = {
      0x1, 0x841, 0x1081, 0x18C1, 0x18C5, 0x2101, 0x2941, 0x2105, 0x2945, 0x3181, 0x39C3, 0x2949, 0x39CD, 0x1D7, 0x2CF, 0x1A5F, 
      0x4201, 0x4A41, 0x4A45, 0x5281, 0x5283, 0x5AC7, 0x4209, 0x420B, 0x5ACB, 0x6301, 0x6B41, 0x6B45, 0x7381, 0x7BC1, 0x630B, 0x6B4B, 
      0x6B4F, 0x738B, 0x7BCF, 0x4211, 0x4A51, 0x4A53, 0x5291, 0x5293, 0x5AD1, 0x5AD5, 0x6311, 0x6B53, 0x7391, 0x6B5B, 0x39AD, 0x18FF, 
      0x20FF, 0x28FF, 0x30FF, 0x38FF, 0x213F, 0x293F, 0x297F, 0x313F, 0x317F, 0x397F, 0x31BF, 0x39FF, 0x263, 0x61AF, 0x40FF, 0x48BF, 
      0x48FF, 0x50BF, 0x50FF, 0x58BF, 0x413F, 0x417F, 0x493F, 0x497F, 0x41BF, 0x41FF, 0x49BF, 0x49FF, 0x513F, 0x597F, 0x51BF, 0x51FF, 
      0x59BF, 0x60BF, 0x60FF, 0x68BF, 0x70BF, 0x78BF, 0x617F, 0x693F, 0x697F, 0x69BB, 0x61BF, 0x61FF, 0x69BF, 0x69FF, 0x717F, 0x793F, 
      0x797F, 0x71FF, 0x423F, 0x4A7F, 0x523F, 0x527F, 0x52BF, 0x5ABF, 0x5AFF, 0x623F, 0x627F, 0x6A3F, 0x62BF, 0x62FF, 0x6ABF, 0x7A7F, 
      0x72BF, 0x633F, 0x6B7F, 0x73BF, 0x7BFF, 0x459, 0x61D, 0x46B, 0x7E1, 0x635, 0xC3C1, 0x887F, 0x80BF, 0x80FF, 0x88BF, 0x907F, 
      0x987F, 0x90BF, 0x90FF, 0x98BF, 0x98FF, 0x817F, 0x893F, 0x897F, 0x81FF, 0x89BF, 0x89FF, 0x913F, 0x993F, 0x91BF, 0x91FF, 0x99BF, 
      0x99FF, 0xA07F, 0xA87F, 0xA0BF, 0xA0FF, 0xA8FF, 0xB07F, 0xB87F, 0xB0FF, 0xB8BF, 0xB8FF, 0xA17F, 0xA97F, 0xA1BF, 0xA1FF, 0xA9BF, 
      0xB17F, 0xB93F, 0xB97F, 0xB1BF, 0xB9BF, 0x823F, 0x827F, 0x8A3F, 0x923F, 0xC03F, 0xC07F, 0xC83F, 0xC87F, 0xC0BF, 0xC8FF, 0xD03F, 
      0xD83F, 0xD87F, 0xD0BF, 0xD0FF, 0xC1BF, 0xC9BF, 0xD9BF, 0xE03F, 0xE07F, 0xE83F, 0xE87F, 0xE0BF, 0xF03F, 0xF07F, 0xF7BF, 0xE1BF, 
      0xF1BF, 0xF9FF, 0xFA3F, 0xFA7F, 0xFB3F, 0xFBBF, 0x8401, 0x8C41, 0x8405, 0x8C45, 0x9481, 0x9CC1, 0x8409, 0x840F, 0x948B, 0xA501, 
      0xAD41, 0xBDC1, 0xBDC7, 0xA50B, 0xAD49, 0xFCC1, 0xED0D, 0xCE41, 0xCE45, 0xDEC1, 0xDEC3, 0xE701, 0xF781, 0xFFC1, 0xFF0D, 0xFE51, 
      0xFFD3, 0xFFD5, 0xFFDB, 0x94A5, 0x843F, 0x8C7F, 0x8CBF, 0x94BF, 0x94FF, 0x9CFF, 0xA53F, 0xA57F, 0xAD7F, 0xADBF, 0xBDFF, 0xBE3F, 
      0xA7F3, 0xA77F, 0xFC7F, 0xFD3F, 0xFDFF, 0xCE73, 0xCE7F, 0xCEBF, 0xDEFF, 0xCFF1, 0xDF3F, 0xFE3F, 0xEF7F, 0xF83F, 0xFFBF, 0xFFFF
      
};*/

struct save_file
{
	char header[10] ; // _dstar_
	unsigned char nb_saves ;
} ;

struct save
{
	ushort nb_moves ;
	ushort time ;
} ;

struct save_file header ;
struct save pz_save[100] ;

void read_save_file(void)
{
	F_HANDLE hfile;
	
	ulong nb_map ;
	short cpt ;
		
	if (SM_OK != GpFileOpen("gp:\\gpmm\\dstar\\dstar.sav", OPEN_R, &hfile))
	{		
		struct save save ;

		GpFileCreate("gp:\\gpmm\\dstar\\dstar.sav",ALWAYS_CREATE, &hfile);
		GpDirEnumNum ("gp:\\gpmm\\dstar\\map\\",&nb_map) ;
		nb_map-=2 ; // remove . and ..

		save.time = 0 ;
		save.nb_moves = 0 ;
		GPSTRCPY(header.header,"_dstar_");
		header.nb_saves = nb_map ;

		GpFileWrite(hfile,&header,sizeof(struct save_file));
		
		for(cpt=0;cpt<100;cpt++)	GpFileWrite(hfile,&save,sizeof(struct save));
	
		GpFileClose(hfile) ;

		read_save_file() ;
	}
	else
	{
		unsigned long m_size=0 ;
				
		GpFileRead(hfile,&header,sizeof(struct save_file),&m_size);
		
		GpDirEnumNum ("gp:\\gpmm\\dstar\\map\\",&nb_map) ;
		header.nb_saves = nb_map-2 ;
		
		for(cpt=0;cpt<256;cpt++)	GpFileRead(hfile,&pz_save[cpt],sizeof(struct save),&m_size);
		
		GpFileClose(hfile) ;
		
		if(GPSTRCMP("_dstar_",header.header))
		{
			GpFileRemove("gp:\\gpmm\\dstar\\dstar.sav") ;
			read_save_file() ;
		}
	}
}

void write_save_file(void)
{
	F_HANDLE hfile;
	short cpt ;
	
	GpFileOpen("gp:\\gpmm\\dstar\\dstar.sav", OPEN_W, &hfile) ;
	
	GpFileWrite(hfile,&header,sizeof(struct save_file));
	
	for(cpt=0;cpt<256;cpt++)	GpFileWrite(hfile,&pz_save[cpt],sizeof(struct save));

	GpFileClose(hfile) ;	
}

void edit_map()
{
	short exit=0 ;

	GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;
	//map_header = read_map_file_with_tile(&level,buffer,theme_header.bmp_data) ;
	map_header = read_map_file(&level,buffer) ;

	load_animated_tile(&level,(unsigned char *)etoile,20,7,0,30,0) ;
	load_animated_tile(&level,(unsigned char *)trou_noir,4,4,0,100,0) ;

	if(instant_key(64))	while(!down_front(64)) refresh_key() ;

	do {
		refresh_key() ;
		
		//if(level.transp_color) GpRectFill(NULL, &gpDraw[nflip], 0, 0, 320, 240, 0xFE);

		//folow_gfx(&level,&curseur, 80,80,80,80) ;

		//if(level.size_tile_x == 32)	draw_map_animated_32(&level) ;
		//else				draw_map_animated_16(&level) ;

			for(cpt_x=0;cpt_x<20;cpt_x++)
				for(cpt_y=0;cpt_y<15;cpt_y++)
				{
					switch(level.map[cpt_y*20 + cpt_x])
					{
						case 5 : draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ; break ;
						case 0 : draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ; break ;

						case 7 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,7,cpt_x<<4,cpt_y<<4) ;
						break ;
						
						case 1 : draw_tile_xy(&level,1,cpt_x<<4,cpt_y<<4) ; break ;
												
						case 2 : draw_tile_xy(&level,2,cpt_x<<4,cpt_y<<4) ; break ;
						
						case 6 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,6,cpt_x<<4,cpt_y<<4) ;
						
						break ;
						
						case 3 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,3,cpt_x<<4,cpt_y<<4) ;
						break ;
							 
						case 4 :
							 draw_tile_xy(&level,5,cpt_x<<4,cpt_y<<4) ;
							 draw_tile_xy(&level,4,cpt_x<<4,cpt_y<<4) ;
						break ;
					}
				} ;

		//if(nflip) GpBitBlt(NULL,&gpDraw[nflip],tile_draw_x,10,39,229,(uchar *)bg_tileset,0,0,39,229);
		if(nflip) GpRectFill(NULL, &gpDraw[nflip], tile_draw_x, 20, 20, 200, 0x9);

		if(!nflip)
		{
			get_start_pos_of_a_tile(&level,curseur.pos_x-level.scrool_x,curseur.pos_y-level.scrool_y,&startx,&starty) ;
			GpRectFill(NULL, &gpDraw[nflip], startx-level.scrool_x, starty-level.scrool_y, level.size_tile_x, level.size_tile_y, 0x9);
		}

		if((tile_value_A-2) > 0)
			if(nflip) draw_tile_xy(&level,tile_value_A-2,2+tile_draw_x,40) ;

		if((tile_value_A-1) >= 0)
			if(nflip) draw_tile_xy(&level,tile_value_A-1,2+tile_draw_x,75) ;
		
		if(!nflip) GpRectFill(NULL, &gpDraw[nflip],tile_draw_x,108,20,20,0xFF);
		
		draw_tile_xy(&level,tile_value_A,2+tile_draw_x,110) ;

		if(tile_value_A != level.nb_tiles-1) if(nflip) draw_tile_xy(&level,tile_value_A+1,2+tile_draw_x,145) ;
		
		if(tile_value_A != level.nb_tiles-2) if(nflip) draw_tile_xy(&level,tile_value_A+2,2+tile_draw_x,180) ;

		draw_int(&font8,get_tile(&level,curseur.pos_x-level.scrool_x,curseur.pos_y-level.scrool_y),10,10) ;
		draw_int(&font8,tile_value_A,40,10) ;
		
		GPSPRINTF(buffer,"%i (%i)",curseur.pos_x/level.size_tile_x +1,level.size_x) ;
		draw_text(&font8,buffer,10,30) ;
		GPSPRINTF(buffer,"%i (%i)",curseur.pos_y/level.size_tile_y +1,level.size_y) ;
		draw_text(&font8,buffer,10,40) ;

//		if(tile_value_A)
//			if(nflip) draw_tile_xy(&level,tile_value_A-1,290,10) ;

//		draw_tile_xy(&level,tile_value_A,290,45) ;

//		if(tile_value_A != level.nb_tiles-1) if(nflip) draw_tile_xy(&level,tile_value_A+1,290,80) ;
		
		draw_gfx_on_map(&curseur,&level,0,0) ;

		if(up_front(16))
			if(tile_value_A) tile_value_A-- ;
			
		if(up_front(128))
			if(tile_value_A<level.nb_tiles-1) tile_value_A++ ;
		
		if(key_pressed&64)
			set_tile(&level,curseur.pos_x-level.scrool_x,curseur.pos_y-level.scrool_y,tile_value_A) ;
			
		if(up_front(32))	tile_value_A = get_tile(&level,curseur.pos_x-level.scrool_x,curseur.pos_y-level.scrool_y) ;


			
		if(instant_key(1))	// left
			for(cpt=0;cpt<4;cpt++)
				if(curseur.pos_x) curseur.pos_x-- ;

		if(instant_key(4))	// right
			for(cpt=0;cpt<4;cpt++)
				if(curseur.pos_x + curseur.size_x < 319) curseur.pos_x++ ;
				//if(curseur.pos_x + curseur.size_x < level.scrool_x + 320) curseur.pos_x++ ;

		if(instant_key(8))	// up
			for(cpt=0;cpt<4;cpt++)
				if(curseur.pos_y) curseur.pos_y-- ;

		if(instant_key(2))	// down
			for(cpt=0;cpt<4;cpt++)
				if(curseur.pos_y< 235) curseur.pos_y++ ;
				//if(curseur.pos_y + curseur.size_y < level.scrool_y + 240) curseur.pos_y++ ;

		if(tile_draw_x==296)
			if(curseur.pos_x-level.scrool_x > 250) tile_draw_x = 5 ;

		if(tile_draw_x==5)
			if(curseur.pos_x-level.scrool_x < 70) tile_draw_x = 296 ;

		flip_screen() ;

		//if(up_front(512)) exit=1 ;
		
		if(up_front(512))
		{
			long last_key_time = 0 ;
			static char item_selected=1 ;
			char buffer2[10] ;
			short cptx, cpty ;
			
			GPSPRINTF(buffer,"save puzZle %i",curent_map_number) ;
			GPSPRINTF(buffer2,"save as puzZle %i",nombre_de_map) ;
		
			for(cptx=2;cptx<318;cptx+=rand()%2+1)
				for(cpty=2;cpty<238;cpty+=rand()%2+1)
					blur_pixel(cptx+(rand()%2),cpty+(rand()%2)) ;
			flip_screen() ;
	
			for(cptx=3;cptx<318;cptx+=rand()%2+1)
				for(cpty=3;cpty<238;cpty+=rand()%2+1)
					blur_pixel(cptx+(rand()%2),cpty+(rand()%2)) ;
		
			do
			{
				refresh_key() ;

				//draw_center_rect(162,62,0x6) ;
				//draw_center_rect(160,60,0xFF) ;

				//draw_text_center_x_vibrate(&font8,"- optiOns -",70,1) ;

				//draw_menu_item(&font8, buffer, 1, item_selected, 3, 100) ;
				//draw_menu_item(&font8, buffer2, 2, item_selected, 3, 100) ;
				//draw_menu_item(&font8, "back to main menu", 3, item_selected, 3, 100) ;

				if(up_front(8)||instant_key(8)&&(GpTickCountGet() > last_key_time + 150))
				{	if(item_selected > 1) item_selected-- ;		last_key_time = GpTickCountGet() ;	}

				if(up_front(2)||instant_key(2)&&(GpTickCountGet() > last_key_time + 150))
				{	if(item_selected != 3) item_selected++ ;	last_key_time = GpTickCountGet() ;	}

				flip_screen() ;
		
			} while((!up_front(64))&&(!up_front(32))) ;
							
			//old_key = 256 ; // to not load map due to start activated

			if(!up_front(32))	exit=1 ;

			if(exit)
			{
				switch(item_selected)
				{
					case(1) :
						GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%i.map",curent_map_number) ;
						GPSPRINTF(buffer2,"%i",curent_map_number) ;
						copy_map_to_file(&level,buffer,buffer2,"gp:\\gpmm\\dstar\\tile.gpg",NULL,NULL,"Gdl") ;
					break ;
					
					case(2) :
						GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%i.map",nombre_de_map) ;
						GPSPRINTF(buffer2,"%i",nombre_de_map) ;
						copy_map_to_file(&level,buffer,buffer2,"gp:\\gpmm\\dstar\\tile.gpg",NULL,NULL,"Gdl") ;
					break ;	
				}
			}
		}
	
	} while(!exit) ;
	
	free_map(&map_header) ;
}

void choose_skin(char * skin_url)
{
	GPDIRENTRY	liste_fichier[50];
	short select=2,cpt=0, old=1 ;
	char  output[20] ;
	//long tmp=1 ;
	ulong g_cnt_file=0 ;
	
	GpDirEnumList("gp:\\gpmm\\dstar\\skin\\", 0,50,(GPDIRENTRY*)&liste_fichier, &g_cnt_file);
	
	nflip^=1 ;
	
	do{
		refresh_key() ;
		
		if(up_front(2)&&(select != g_cnt_file-1)) select++ ;
		if(up_front(8)&&(select != 2)) select-- ;
		
		if(select != old)
		{
			old = select ;
			
			GpRectFill(NULL, &gpDraw[nflip], 0, 0, 320, 240, 0xff);
			
			for(cpt=2;cpt<g_cnt_file;cpt++)
			{
				if(select==cpt) GPSPRINTF(output,"-> %s",(char*)liste_fichier[cpt].name) ;
				else GPSPRINTF(output,"  %s",(char*)liste_fichier[cpt].name) ;
				
				draw_text_center_x(&font8,output,90 + 10*(cpt - 2)) ;
				
				/*if(cpt-2 <= 5) GpTextOut(NULL,&gpDraw[nflip],50,90 + 10*(cpt - 2),output,15) ;
				else GpTextOut(NULL,&gpDraw[nflip],170,90 + 10*(cpt - 8),output,15) ;*/
			} ;
		
			GPSTRCPY(skin_url,(char*)liste_fichier[select].name) ;			
		}
		
	} while((!up_front(64))&&(!up_front(256))) ;
	
	GPSPRINTF(skin_url,"gp:\\gpmm\\dstar\\skin\\%s",(char*)liste_fichier[select].name) ;
}	

void choose_map(void)
{
 	struct map_file_header header ;
 	short cpt_map, cpt_draw=0 ;	
	char buffer[100] ;
	short old_map_selected = map_selected ;
	char ext[4] ;
	short start=2 ;
	short limit_draw=15 ;
	char num_draw = 0 ;
	char id_select = 0 ;
	long old_tick = 0 ;

	struct map_header tmp_header ;
	struct map tmp_map ;
	ushort id ;
	
	static char refresh = 1 ;
	
	if(map_selected > 16) start = map_selected-8 ;

	if(refresh) { GpDirEnumList("gp:\\gpmm\\dstar\\map",0,256,(GPDIRENTRY*)&liste_des_map,&nombre_de_map) ; refresh=0 ; }

	GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;

	tmp_buf[0] = liste_des_map[map_selected].name[0] ;
	tmp_buf[1] = liste_des_map[map_selected].name[1] ;
	tmp_buf[2] = '\0' ;

	curent_map_number = atoi(tmp_buf) ;

	tmp_header = read_map_file_with_tile(&tmp_map,buffer,yaya) ;

 	do {
		refresh_key() ;

		for(cpt_x=0;cpt_x<20;cpt_x++)
			for(cpt_y=0;cpt_y<15;cpt_y++)
				draw_tile_xy(&tmp_map,5,cpt_x<<4,cpt_y<<4) ;

		draw_text_center_x_vibrate(&font8," .   h o e   l v l  .",10,1) ;
		draw_text_center_x_vibrate(&font8," : c o s  a  e e  :",10,1) ;

		draw_int(&font8,get_free_ram(),5,5) ;

		cpt_draw = 0 ;
		num_draw = 0 ;

		for(cpt_x=0;cpt_x<20;cpt_x++)
			for(cpt_y=0;cpt_y<15;cpt_y++)
			{
				id=tmp_map.map[cpt_y*tmp_map.size_x + cpt_x] ;
				if(id)	GpRectFill (NULL,&gpDraw[nflip],10+cpt_x*5,130+cpt_y*5,4,4,117+id) ;
			} ;

		for(cpt_map=start;(cpt_map<nombre_de_map)&&(num_draw<limit_draw);cpt_map++)
		{
			if(map_selected==cpt_map)
			{				
				gfx_draw_method = 0 ;
				id_select = num_draw ;
			}
			else	gfx_draw_method = 1 ;
			
			get_extention(liste_des_map[cpt_map].name,ext) ;
			
			if(!GPSTRCMP("MAP",(char*)ext))
			{
				draw_text_center_x(&font8,liste_des_map[cpt_map].name,30+cpt_draw*10) ;
				cpt_draw++ ;
				num_draw++ ;
			}
		} ;

		gfx_draw_method = 1 ;

		if((up_front(159))||(instant_key(144)&&(old_tick+20<GpTickCountGet()))||(instant_key(10)&&(old_tick+90<GpTickCountGet()))||(instant_key(5)&&(old_tick+250<GpTickCountGet())))
		{		
			char ok = 0 ;
			old_tick = GpTickCountGet() ;
			old_map_selected = map_selected ;

			if(instant_key(4)) // right
			{
				char cpt ;
				
				for(cpt=0;cpt<10;cpt++)
				{
					if(map_selected != nombre_de_map-1)
					{
						map_selected++ ;
						while((!ok)&&(map_selected != nombre_de_map))
						{	
							get_extention(liste_des_map[map_selected].name,ext) ;
							
							if(GPSTRCMP("MAP",(char*)ext)) map_selected++ ;
							else ok=1 ;
						}
						
						if(!ok) map_selected = old_map_selected ;
						else
						{
							if(id_select != limit_draw)
								if(map_selected - start - 2 == limit_draw-6) start++ ;
						}
					}
				} ;
			}

			if(instant_key(1)) // left
			{
				char cpt ;
				
				for(cpt=0;cpt<10;cpt++)
				{
					if(map_selected != 2)
					{
						map_selected-- ;
						while((!ok)&&(map_selected != 1))
						{	
							get_extention(liste_des_map[map_selected].name,ext) ;
							
							if(GPSTRCMP("MAP",(char*)ext)) map_selected-- ;
							else ok=1 ;
						}
						
						if(!ok) map_selected = old_map_selected ;
						else
						{
								if(start)
									if(map_selected - start - 2 == 1) start-- ;
						}
					}
				} ;
			}


			if(instant_key(16)) // L
			{
				char cpt ;
				
				for(cpt=0;cpt<2;cpt++)
				{
					if(map_selected != 2)
					{
						map_selected-- ;
						while((!ok)&&(map_selected != 1))
						{	
							get_extention(liste_des_map[map_selected].name,ext) ;
							
							if(GPSTRCMP("MAP",(char*)ext)) map_selected-- ;
							else ok=1 ;
						}
						
						if(!ok) map_selected = old_map_selected ;
						else
						{
								if(start)
									if(map_selected - start - 2 == 1) start-- ;
						}
					}
				} ;
			}

			if(instant_key(128)) // R
			{
				char cpt ;
				
				for(cpt=0;cpt<2;cpt++)
				{
					if(map_selected != nombre_de_map-1)
					{
						map_selected++ ;
						while((!ok)&&(map_selected != nombre_de_map))
						{	
							get_extention(liste_des_map[map_selected].name,ext) ;
							
							if(GPSTRCMP("MAP",(char*)ext)) map_selected++ ;
							else ok=1 ;
						}
						
						if(!ok) map_selected = old_map_selected ;
						else
						{
							if(id_select != limit_draw)
								if(map_selected - start - 2 == limit_draw-6) start++ ;
						}
					}
				} ;
			}

			if(instant_key(8)) // up
			{
				if(map_selected != 2)
				{
					map_selected-- ;
					while((!ok)&&(map_selected != 1))
					{	
						get_extention(liste_des_map[map_selected].name,ext) ;
						
						if(GPSTRCMP("MAP",(char*)ext)) map_selected-- ;
						else ok=1 ;
					}
					
					if(!ok) map_selected = old_map_selected ;
					else
					{
							if(start)
								if(map_selected - start - 2 == 1) start-- ;
					}
				}
			}

			if(instant_key(2)) // down
			{
				if(map_selected != nombre_de_map-1)
				{
					map_selected++ ;
					while((!ok)&&(map_selected != nombre_de_map))
					{	
						get_extention(liste_des_map[map_selected].name,ext) ;
						
						if(GPSTRCMP("MAP",(char*)ext)) map_selected++ ;
						else ok=1 ;
					}
	
					if(!ok) map_selected = old_map_selected ;
					else
					{
						if(id_select != limit_draw)
							if(map_selected - start - 2 == limit_draw-6) start++ ;
					}
				}
			}
		
			if(old_map_selected != map_selected)
			{
				//if(down_front(159)||(!key_pressed))
				{
					// read map
					GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;
					
					free_map(&tmp_header) ;
					tmp_header = read_map_file_with_tile(&tmp_map,buffer,yaya) ;
				}
					tmp_buf[0] = liste_des_map[map_selected].name[0] ;
					tmp_buf[1] = liste_des_map[map_selected].name[1] ;
					tmp_buf[2] = '\0' ;
	
					curent_map_number = atoi(tmp_buf) ;
			}
		}

		draw_text(&font8,"puzzle",10,50) ;
		draw_text(&font8,"move",18,60) ;
		draw_text(&font8,"time",18,70) ;
		
		draw_int(&font8,curent_map_number,70,50) ;
		draw_int(&font8,pz_save[curent_map_number].nb_moves,70,60) ;
		draw_int(&font8,pz_save[curent_map_number].time,70,70) ;
		
		flip_screen() ;

		if(up_front(512))	// option menu
		{
			short cptx, cpty ;
			
			//struct map temp ;
			long last_key_time = 0 ;
			static char item_selected=1 ;
			//char buffer[9] ;
			
			GPSPRINTF(buffer,"edit puzZle %i",curent_map_number) ;
		
			for(cptx=2;cptx<318;cptx+=rand()%2+1)
				for(cpty=2;cpty<238;cpty+=rand()%2+1)
					blur_pixel(cptx+(rand()%2),cpty+(rand()%2)) ;
			flip_screen() ;

			for(cptx=3;cptx<318;cptx+=rand()%2+1)
				for(cpty=3;cpty<238;cpty+=rand()%2+1)
					blur_pixel(cptx+(rand()%2),cpty+(rand()%2)) ;

			do
			{
				refresh_key() ;

				//draw_center_rect(162,82,0x6) ;
				//draw_center_rect(160,80,0xFF) ;

				//draw_text_center_x_vibrate(&font8,"- optiOns -",70,1) ;

				//draw_menu_item(&font8, "muZik", 1, item_selected, 5, 100) ;
				//draw_menu_item(&font8, buffer, 2, item_selected, 5, 100) ;
				//draw_menu_item(&font8, "create new puzZle", 3, item_selected, 5, 100) ;
				//draw_menu_item(&font8, "exit dstar", 4, item_selected, 5, 100) ;
				//draw_menu_item(&font8, "about", 5, item_selected, 5, 100) ;

				if(up_front(8)||instant_key(8)&&(GpTickCountGet() > last_key_time + 150))
				{	if(item_selected > 1) item_selected-- ;		last_key_time = GpTickCountGet() ;	}

				if(up_front(2)||instant_key(2)&&(GpTickCountGet() > last_key_time + 150))
				{	if(item_selected != 5) item_selected++ ;	last_key_time = GpTickCountGet() ;	}

				flip_screen() ;
		
			} while((!up_front(64))&&(!up_front(32))) ;

			if(up_front(64))
				switch(item_selected)
				{
					ushort l,h ;
					char url[100] ;
					
					case 1 :	// muZik menu
						//music_menu() ;
					break ;

					case 2 :	// edit map
						edit_map() ;

						key_pressed=0 ;
						gfx_draw_method = 1 ;
						tile_draw_method = 1 ;
						
					 	cpt_draw=0 ;	
						old_map_selected = map_selected ;
						start=2 ;
						limit_draw=15 ;
						num_draw = 0 ;
						id_select = 0 ;
						old_tick = 0 ;
					
						if(map_selected > 16) start = map_selected-8 ;
					
						GpDirEnumList("gp:\\gpmm\\dstar\\map",0,100,(GPDIRENTRY*)&liste_des_map,&nombre_de_map) ;
					
						GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;
						header = read_map_header(buffer) ;
					
						tmp_buf[0] = liste_des_map[map_selected].name[0] ;
						tmp_buf[1] = liste_des_map[map_selected].name[1] ;
						tmp_buf[2] = '\0' ;
					
						curent_map_number = atoi(tmp_buf) ;
					break ;

					case 3 :	// create new map
						//new_map() ;
					break ;

					case 4 :	// reboot
						GpAppExit() ;
					break ;

					case 5 :	// about :)						
						choose_skin(skin_url) ;

						GPSPRINTF(url,"%s\\thm.pcx",skin_url) ;
						_free(yaya) ;
						yaya = load_pcx(url) ;
						taille_pcx(url,&l,&h) ;
						charge_palette_pcx(url,tiles_Pal) ;
						fade_to_palette(0,tiles_Pal) ;						
						yaya = (uchar *)convert_8b_to_16b(yaya,l,h,(uint*)HARDWARE_PALETTE) ;

						GPSPRINTF(buffer,"gp:\\gpmm\\dstar\\map\\%s",liste_des_map[map_selected].name) ;
						free_map(&tmp_header) ;
						tmp_header = read_map_file_with_tile(&tmp_map,buffer,yaya) ;
					break ;
				}

			
				
			old_key = 256 ; // to not load map due to start activated
		}

	} while(!up_front(256)) ;

	key_pressed=0 ;
	gfx_draw_method = 1 ;
	tile_draw_method = 1 ;
	
	free_map(&tmp_header) ;
}

