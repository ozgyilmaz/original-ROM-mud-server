/***************************************************************************
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *
 *  Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.   *
 *                                                                         *
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *
 *  Chastain, Michael Quan, and Mitchell Tse.                              *
 *                                                                         *
 *  In order to use any part of this Merc Diku Mud, you must comply with   *
 *  both the original Diku license in 'license.doc' as well the Merc       *
 *  license in 'license.txt'.  In particular, you may not remove either of *
 *  these copyright notices.                                               *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 ***************************************************************************/

/***************************************************************************
*	ROM 2.4 is copyright 1993-1998 Russ Taylor			   *
*	ROM has been brought to you by the ROM consortium		   *
*	    Russ Taylor (rtaylor@hypercube.org)				   *
*	    Gabrielle Taylor (gtaylor@hypercube.org)			   *
*	    Brian Moore (zump@rom.org)					   *
*	By using this code, you have agreed to follow the terms of the	   *
*	ROM license, in the file Rom24/doc/rom.license			   *
***************************************************************************/

#if defined(macintosh)
#include <types.h>
#else
#include <sys/types.h>
#endif
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "merc.h"
#include "recycle.h"
#include "rom_mysql.h"

MYSQL *DB_CONNECT()
{
	MYSQL *hnd;

	if ( (hnd = mysql_init(NULL)) == NULL )
		return NULL;

	if ( mysql_real_connect(hnd,DB_SERVER,DB_USER,DB_PASSWORD,DB_NAME,0,NULL,0) == NULL )
		return NULL;

	return hnd;
}

void mysql_escape_string(char *query, char *escaped)
{
	char 	*point_orig, *point_escaped;

	if(!query)
	{
		return;
	}

	point_escaped = escaped;
	for(point_orig=query;*point_orig;point_orig++)
	{
		if( *point_orig == '\'' )
		{
			*point_escaped = '\\';
			point_escaped++;
		}
		*point_escaped = *point_orig;
		point_escaped++;
	}

	return;

}

void mysql_execute_query(char *query, int i)
{
	MYSQL *hnd;

	hnd = DB_CONNECT();

	if( hnd == NULL )
		return;

	if(mysql_real_query( hnd , query , strlen( query ) ) != 0 )
	{
			bug("mysql_real_query() error:\n\r",0);
			bug(query,0);
	}

	mysql_close( hnd );
}

void mysql_log_communication( char *channel , CHAR_DATA *ch, CHAR_DATA *victim , int room_vnum , char *data )
{
	char datetime[100];
	char query[ MAX_STRING_LENGTH ];

	strftime(datetime, sizeof(datetime), "%Y-%m-%d %X", localtime(&current_time));

	sprintf( query , "INSERT INTO `pc_communication` VALUES( '' , '%s' , '%s' , '%s' ,'%s' , '%d' , '%s' )" , (char*)datetime , channel , (ch!=NULL)?ch->name:(char*)"" , (victim!=NULL)?victim->name:(char*)"",room_vnum , data );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_area( AREA_DATA *pArea )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];
	char arg3[MAX_STRING_LENGTH];
	char arg4[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));
	memset(arg3,0,sizeof(arg3));
	memset(arg4,0,sizeof(arg3));

	mysql_escape_string(pArea->file_name,arg1);
	mysql_escape_string(pArea->name,arg2);
	mysql_escape_string(pArea->writer,arg3);
	mysql_escape_string(pArea->credits,arg4);

	sprintf( query , "INSERT INTO `area` VALUES( '' , '%s' , '%s' , '%s' , '%s' ,'%d' , '%d' , '%d' , '%d' )" , arg1 , arg2 , arg3 , arg4 , pArea->low_range ,pArea->high_range , pArea->min_vnum , pArea->max_vnum );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_room( ROOM_INDEX_DATA *pRoomIndex )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];
	char arg3[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));
	memset(arg3,0,sizeof(arg3));

	mysql_escape_string(pRoomIndex->name,arg1);
	mysql_escape_string(pRoomIndex->description,arg2);
	mysql_escape_string(pRoomIndex->owner,arg3);

	sprintf( query , "INSERT INTO `room` VALUES( '' , '%d' , '%s' , '%s' , '%s' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' )" , \
	pRoomIndex->vnum, arg1, arg2, arg3, pRoomIndex->room_flags,
	pRoomIndex->light, pRoomIndex->sector_type, pRoomIndex->heal_rate, pRoomIndex->mana_rate, pRoomIndex->clan );

	mysql_execute_query(query,1);

	return;
}

void mysql_write_exit( EXIT_DATA *pexit, int room_vnum, int door )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));

	mysql_escape_string(pexit->description,arg1);
	mysql_escape_string(pexit->keyword,arg2);

	sprintf( query , "INSERT INTO `exit` VALUES( '' , '%d' , '%d' , '%s' , '%s' , '%d' , '%d' , '%d' )" , \
	room_vnum, door, arg1, arg2, pexit->exit_info, pexit->key, pexit->u1.vnum );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_room_extra_description( EXTRA_DESCR_DATA *ed, int room_vnum )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));

	mysql_escape_string(ed->keyword,arg1);
	mysql_escape_string(ed->description,arg2);

	sprintf( query , "INSERT INTO `room_extra_description` VALUES( '' , '%d' , '%s' , '%s' )" , \
	room_vnum, arg1, arg2 );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_help( HELP_DATA *pHelp )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));

	mysql_escape_string(pHelp->keyword,arg1);
	mysql_escape_string(pHelp->text,arg2);

	sprintf( query , "INSERT INTO `help` VALUES( '' , '%d' , '%s' , '%s' )" , \
	pHelp->level, arg1, arg2 );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_social( char *name, char *char_no_arg, char *others_no_arg, char *char_found, char *others_found, char *vict_found, char *char_not_found, char *char_auto, char *others_auto )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];
	char arg3[MAX_STRING_LENGTH];
	char arg4[MAX_STRING_LENGTH];
	char arg5[MAX_STRING_LENGTH];
	char arg6[MAX_STRING_LENGTH];
	char arg7[MAX_STRING_LENGTH];
	char arg8[MAX_STRING_LENGTH];
	char arg9[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));
	memset(arg3,0,sizeof(arg3));
	memset(arg4,0,sizeof(arg4));
	memset(arg5,0,sizeof(arg5));
	memset(arg6,0,sizeof(arg6));
	memset(arg7,0,sizeof(arg7));
	memset(arg8,0,sizeof(arg8));
	memset(arg9,0,sizeof(arg9));

	mysql_escape_string(name,arg1);
	mysql_escape_string(char_no_arg,arg2);
	mysql_escape_string(others_no_arg,arg3);
	mysql_escape_string(char_found,arg4);
	mysql_escape_string(others_found,arg5);
	mysql_escape_string(vict_found,arg6);
	mysql_escape_string(char_not_found,arg7);
	mysql_escape_string(char_auto,arg8);
	mysql_escape_string(others_auto,arg9);

	sprintf( query , "INSERT INTO `social` VALUES( '' , '%s' , '%s' , '%s' , '%s' , '%s' , '%s' , '%s' , '%s' , '%s' )" , \
	arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_shop( SHOP_DATA *pShop )
{
	char query[ MAX_STRING_LENGTH ];

	sprintf( query , "INSERT INTO `shop` VALUES( '' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' )" , \
	pShop->keeper, pShop->buy_type[0], pShop->buy_type[1], pShop->buy_type[2], pShop->buy_type[3], pShop->buy_type[4],
 	pShop->profit_buy, pShop->profit_sell , pShop->open_hour, pShop->close_hour );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_reset( RESET_DATA *pReset )
{
	char query[ MAX_STRING_LENGTH ];

	sprintf( query , "INSERT INTO `reset` VALUES( '' , '%c' , '%d' , '%d' , '%d' , '%d' )" , \
	pReset->command, pReset->arg1, pReset->arg2, pReset->arg3, pReset->arg4 );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_mobile( MOB_INDEX_DATA *pMobIndex )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];
	char arg3[MAX_STRING_LENGTH];
	char arg4[MAX_STRING_LENGTH];
	char arg5[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));
	memset(arg3,0,sizeof(arg3));
	memset(arg4,0,sizeof(arg4));
	memset(arg5,0,sizeof(arg5));

	mysql_escape_string(pMobIndex->player_name,arg1);
	mysql_escape_string(pMobIndex->short_descr,arg2);
	mysql_escape_string(pMobIndex->long_descr,arg3);
	mysql_escape_string(pMobIndex->description,arg4);
	mysql_escape_string(pMobIndex->material,arg5);

	sprintf( query , "INSERT INTO `mobile` VALUES( '' , '%d' , '%d' , '%d' , '%s' , '%s' , '%s' , '%s' , \
	'%ld' , '%ld' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , \
	'%d' , '%d' , '%d' , '%d' , '%d' , '%ld' , '%ld' , '%ld' , '%ld' , '%d' , '%d' , '%d' , '%d' , '%ld' , \
	'%ld' , '%ld' , '%d' , '%s' , '' )" , \
	pMobIndex->vnum, pMobIndex->group, pMobIndex->new_format, arg1, arg2, arg3,
 	arg4, pMobIndex->act, pMobIndex->affected_by, pMobIndex->alignment, pMobIndex->level, pMobIndex->hitroll,
	pMobIndex->hit[0], pMobIndex->hit[1], pMobIndex->hit[2], pMobIndex->mana[0], pMobIndex->mana[1], pMobIndex->mana[2],
	pMobIndex->damage[0], pMobIndex->damage[1], pMobIndex->damage[2], pMobIndex->ac[0], pMobIndex->ac[1], pMobIndex->ac[2],
	pMobIndex->ac[3], pMobIndex->dam_type, pMobIndex->off_flags, pMobIndex->imm_flags, pMobIndex->res_flags, pMobIndex->vuln_flags,
	pMobIndex->start_pos, pMobIndex->default_pos, pMobIndex->sex, pMobIndex->race, pMobIndex->wealth, pMobIndex->form,
	pMobIndex->parts, pMobIndex->size, arg5);

	mysql_execute_query(query,0);

	return;
}

void mysql_write_object_affect_data( AFFECT_DATA *paf, int object_vnum  )
{
	char query[ MAX_STRING_LENGTH ];

	sprintf( query , "INSERT INTO `object_affect_data` VALUES( '' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' )" , \
	object_vnum, paf->valid, paf->where, paf->type, paf->level, paf->duration, paf->location, paf->modifier, paf->bitvector );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_object_extra_description( EXTRA_DESCR_DATA *ed, int object_vnum )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));

	mysql_escape_string(ed->keyword,arg1);
	mysql_escape_string(ed->description,arg2);

	sprintf( query , "INSERT INTO `object_extra_description` VALUES( '' , '%d' , '%s' , '%s' )" , \
	object_vnum, arg1, arg2 );

	mysql_execute_query(query,0);

	return;
}

void mysql_write_object( OBJ_INDEX_DATA *pObjIndex )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];
	char arg2[MAX_STRING_LENGTH];
	char arg3[MAX_STRING_LENGTH];
	char arg4[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));
	memset(arg2,0,sizeof(arg2));
	memset(arg3,0,sizeof(arg3));
	memset(arg4,0,sizeof(arg4));

	mysql_escape_string(pObjIndex->name,arg1);
	mysql_escape_string(pObjIndex->short_descr,arg2);
	mysql_escape_string(pObjIndex->description,arg3);
	mysql_escape_string(pObjIndex->material,arg4);

	sprintf( query , "INSERT INTO `object` VALUES( '' , '%d' , '%d' , '%s' , '%s' , '%s' , '%d' , '%s' , \
	'%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d' , '%d')" , \
	pObjIndex->vnum, pObjIndex->new_format, arg1, arg2, arg3, pObjIndex->reset_num,
 	arg4, pObjIndex->item_type, pObjIndex->extra_flags, pObjIndex->wear_flags, pObjIndex->level, pObjIndex->condition,
	pObjIndex->weight, pObjIndex->cost, pObjIndex->value[0], pObjIndex->value[1], pObjIndex->value[2], pObjIndex->value[3],
	pObjIndex->value[4]);

	mysql_execute_query(query,0);

	return;
}

void mysql_write_mobile_special( MOB_INDEX_DATA *pMobIndex, char *name )
{
	char query[ MAX_STRING_LENGTH ];
	char arg1[MAX_STRING_LENGTH];

	memset(arg1,0,sizeof(arg1));

	mysql_escape_string(name,arg1);

	sprintf( query , "UPDATE `mobile` SET `spec_fun` = '%s' WHERE `vnum` = %d" , arg1, pMobIndex->vnum );

	mysql_execute_query(query,0);

	return;
}
