/****************************************************************************
 *                   ^     +----- |  / ^     ^ |     | +-\                  *
 *                  / \    |      | /  |\   /| |     | |  \                 *
 *                 /   \   +---   |<   | \ / | |     | |  |                 *
 *                /-----\  |      | \  |  v  | |     | |  /                 *
 *               /       \ |      |  \ |     | +-----+ +-/                  *
 ****************************************************************************
 * AFKMud Copyright 1997-2007 by Roger Libiez (Samson),                     *
 * Levi Beckerson (Whir), Michael Ward (Tarl), Erik Wolfe (Dwip),           *
 * Cameron Carroll (Cam), Cyberfox, Karangi, Rathian, Raine, and Adjani.    *
 * All Rights Reserved.                                                     *
 *                                                                          *
 * External contributions from Xorith, Quixadhal, Zarius, and many others.  *
 *                                                                          *
 * Original SMAUG 1.4a written by Thoric (Derek Snider) with Altrag,        *
 * Blodkai, Haus, Narn, Scryn, Swordbearer, Tricops, Gorog, Rennard,        *
 * Grishnakh, Fireblade, and Nivek.                                         *
 *                                                                          *
 * Original MERC 2.1 code by Hatchet, Furey, and Kahn.                      *
 *                                                                          *
 * Original DikuMUD code by: Hans Staerfeldt, Katja Nyboe, Tom Madsen,      *
 * Michael Seifert, and Sebastian Hammer.                                   *
 ****************************************************************************
 *                       Intermud-3 Network Module                          *
 ****************************************************************************/

/*
 * Copyright (c) 2000 Fatal Dimensions
 *
 * See the file "LICENSE" or information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 */

/*
 * Ported to Smaug 1.4a by Samson of Alsherok.
 * Consolidated for cross-codebase compatibility by Samson of Alsherok.
 * Modifications and enhancements to the code
 * Copyright (c)2001-2002 Roger Libiez ( Samson )
 * Registered with the United States Copyright Office
 * TX 5-562-404
 *
 * Contains codebase specific defines to make the rest of it all work - hopefully.
 * Anything your codebase needs to alter is more than likely going to be stored in here.
 * This should be the only file you need to edit to solve unforseen compiling problems
 * if I've done this properly. And remember, this is all based on what these defines mean
 * in your STOCK code. If you've made adjustments to any of it, then you'll need to adjust
 * them here too.
 */

#if defined(I3SMAUG) || defined(I3CHRONICLES)
   #define SMAUGSOCIAL
   #define SOCIAL_DATA SOCIALTYPE
   #define I3STRALLOC STRALLOC
   #define I3STRFREE STRFREE
   #define CH_I3DATA(ch)	 ((ch)->pcdata->i3chardata)
   #define CH_I3LEVEL(ch)		 ((ch)->level)
   #define CH_I3NAME(ch)		 ((ch)->name)
   #define CH_I3TITLE(ch) 	 ((ch)->pcdata->title)
   #define CH_I3RANK(ch)		 ((ch)->pcdata->rank)
   #define CH_I3SEX(ch)		 ((ch)->sex)
   #define CH_LOGON(ch)		 (&(ch)->logon)
   #define CH_CLASSNAME(ch)	 (class_table[(ch)->class]->who_name)
   #define CH_CLAN(ch)		 ((ch)->pcdata->clan)
   #define CH_CLANNAME(ch)	 ((ch)->pcdata->clan->name)
   #define CH_CLANLEADNAME(ch) ((ch)->pcdata->clan->leader)
   #define CH_CLANONENAME(ch)  ((ch)->pcdata->clan->number1)
   #define CH_CLANTWONAME(ch)  ((ch)->pcdata->clan->number2)
   #define CH_CLANLEADRANK(ch) ((ch)->pcdata->clan->leadrank)
   #define CH_CLANONERANK(ch)  ((ch)->pcdata->clan->onerank)
   #define CH_CLANTWORANK(ch)  ((ch)->pcdata->clan->tworank)
#endif

#ifdef I3ROM
   #define first_descriptor descriptor_list
   #define I3STRALLOC str_dup
   #define I3STRFREE free_string
   #define CH_I3DATA(ch)	 ((ch)->pcdata->i3chardata)
   #define CH_I3LEVEL(ch)		((ch)->level)
   #define CH_I3NAME(ch)		((ch)->name)
   #define CH_I3TITLE(ch) 	((ch)->pcdata->title)
   #define CH_LOGON(ch)		(&(ch)->logon)
   #define CH_I3SEX(ch)		((ch)->sex)
   #define CH_CLAN(ch)		((ch)->clan)
   #define CH_CLANNAME(ch)	(clan_table[(ch)->clan].who_name)
   #define CH_CLANLEADNAME(ch) ( 0 == 1 )
   #define CH_CLANONENAME(ch)  ( 0 == 1 )
   #define CH_CLANTWONAME(ch)  ( 0 == 1 )
   #define CH_CLANLEADRANK(ch) ( "Leader" )
   #define CH_CLANONERANK(ch)  ( "First Officer" )
   #define CH_CLANTWORANK(ch)  ( "Second Officer" )
   #define CH_CLASSNAME(ch)	(class_table[(ch)->class].who_name)
   #define CH_I3RANK(ch)		(title_table[(ch)->class][(ch)->level][(ch)->sex == SEX_FEMALE ? 1 : 0])
#endif

#ifdef I3MERC
   #define first_descriptor descriptor_list
   #define I3STRALLOC str_dup
   #define I3STRFREE free_string
   #define CH_I3DATA(ch)	 ((ch)->pcdata->i3chardata)
   #define CH_I3LEVEL(ch)		((ch)->level)
   #define CH_I3NAME(ch)		((ch)->name)
   #define CH_I3SEX(ch)		((ch)->sex)
   #define CH_LOGON(ch)		(&(ch)->logon)
   #define CH_I3TITLE(ch) 	((ch)->pcdata->title)
   #define CH_CLASSNAME(ch)	(class_table[(ch)->class].who_name)
   #define CH_I3RANK(ch)		(title_table[(ch)->class][(ch)->level][(ch)->sex == SEX_FEMALE ? 1 : 0])
   #define CH_CLAN(ch)		( 0 == 1 )
   #define CH_CLANNAME(ch)	( 0 == 1 )
   #define CH_CLANLEADNAME(ch) ( 0 == 1 )
   #define CH_CLANONENAME(ch)  ( 0 == 1 )
   #define CH_CLANTWONAME(ch)  ( 0 == 1 )
   #define CH_CLANLEADRANK(ch) ( "Leader" )
   #define CH_CLANONERANK(ch)  ( "First Officer" )
   #define CH_CLANTWORANK(ch)  ( "Second Officer" )
#endif

#ifdef I3UENVY
   #define SMAUGSOCIAL
   #define SOCIAL_DATA SOC_INDEX_DATA
   SOC_INDEX_DATA *find_social( char *command );
   #define first_descriptor descriptor_list
   #define I3STRALLOC str_dup
   #define I3STRFREE free_string
   #define CH_I3DATA(ch)	 ((ch)->pcdata->i3chardata)
   #define CH_I3LEVEL(ch)         ((ch)->level)
   #define CH_I3NAME(ch)          ((ch)->name)
   #define CH_I3TITLE(ch)         ((ch)->pcdata->title)
   #define CH_I3SEX(ch)		  ((ch)->sex)
   #define CH_LOGON(ch)		  (&(ch)->logon)
   #define CH_CLASSNAME(ch)     (class_table[(ch)->class]->name)
   #define CH_I3RANK(ch)		  (title_table[(ch)->class][(ch)->level][(ch)->sex == SEX_FEMALE ? 1 : 0])
   #define CH_CLAN(ch)          ((ch)->pcdata->clan)
   #define CH_CLANNAME(ch)      ((ch)->pcdata->clan->who_name)
   #define CH_CLANLEADNAME(ch) ((ch)->pcdata->clan->overlord)
   #define CH_CLANONENAME(ch)  ( 0 == 1 )
   #define CH_CLANTWONAME(ch)  ( 0 == 1 )
   #define CH_CLANLEADRANK(ch) ( "Overlord" )
   #define CH_CLANONERANK(ch)  ( "Chieftan" )
   #define CH_CLANTWORANK(ch)  ( "Second Officer" )
#endif

#ifdef I3ACK
   extern int max_players;
   #define first_descriptor first_desc
   #define I3STRALLOC str_dup
   #define I3STRFREE free_string
   #define CH_I3DATA(ch)	 ((ch)->pcdata->i3chardata)
   #define CH_I3LEVEL(ch)		((ch)->level)
   #define CH_I3NAME(ch)		((ch)->name)
   #define CH_I3TITLE(ch) 	((ch)->pcdata->title)
   #define CH_I3SEX(ch)		((ch)->sex)
   #define CH_LOGON(ch)		(&(ch)->logon)
   #define CH_CLASSNAME(ch)	(class_table[(ch)->class].who_name)
   #define CH_I3RANK(ch)		(class_table[(ch)->class].who_name)
   #define CH_CLAN(ch)		((ch)->pcdata->clan)
   #define CH_CLANNAME(ch)	(clan_table[(ch)->pcdata->clan].clan_name)
   #define CH_CLANLEADNAME(ch) (clan_table[(ch)->pcdata->clan].leader)
   #define CH_CLANONENAME(ch)  ( 0 == 1 )
   #define CH_CLANTWONAME(ch)  ( 0 == 1 )
   #define CH_CLANLEADRANK(ch) ( "Leader" )
   #define CH_CLANONERANK(ch)  ( "First Officer" )
   #define CH_CLANTWORANK(ch)  ( "Second Officer" )
#endif

#ifdef I3CIRCLE
//   #if _CIRCLEMUD < CIRCLEMUD_VERSION(3, 0, 21)
//   #  error "Requires CircleMUD 3.0 bpl21+ (varargs output functions)"
//   #endif

   /* This should be in an act.social.h, if it existed. Introducing
      it in an I3 patch would be too intrusive. */
   struct social_messg 
   {
     int act_nr;
     int hide;
     int min_victim_position;
     char *char_no_arg;
     char *others_no_arg;
     char *char_found;
     char *others_found;
     char *vict_found;
     char *not_found;
     char *char_auto;
     char *others_auto;
   };
   #define social_table soc_mess_list
   extern struct social_messg *soc_mess_list;
   #define SMAUGSOCIAL
   struct social_messg *find_social(const char *name);

   typedef struct social_messg SOCIAL_DATA;
   typedef struct char_data CHAR_DATA;
   typedef struct descriptor_data DESCRIPTOR_DATA;

   const char *title_female(int chclass, int level);
   const char *title_male(int chclass, int level);

   #define first_descriptor		descriptor_list
   #define current_time			time(NULL)
   #define I3STRALLOC			strdup
   #define I3STRFREE			free
   #define log_string			basic_mud_log
   #define bug				basic_mud_log
   #define URANGE(a, b, c)		((b) < (a) ? (a) : ((b) > (c) ? (c) : (b)))
   #define write_to_buffer(d, txt, n)	write_to_output((txt), (d))
   #define IS_IMMORTAL(ch)		(GET_LEVEL(ch) >= LVL_IMMORT)
   #define CH_I3DATA(ch)	 ((ch)->player_specials)
   #define CH_I3LEVEL(ch)          GET_LEVEL(ch)
   #define CH_I3NAME(ch)           GET_NAME(ch)
   #define CH_I3TITLE(ch)          GET_TITLE(ch)
   #define CH_I3RANK(ch)           (GET_SEX(ch) == SEX_FEMALE ? title_female(GET_CLASS(ch), GET_LEVEL(ch)) : title_male(GET_CLASS(ch), GET_LEVEL(ch)))
   #define CH_I3SEX(ch)            GET_SEX(ch)
   #define CH_CLASSNAME(ch)      CLASS_ABBR(ch)
   #define CH_CLAN(ch)           FALSE
   #define CH_CLANNAME(ch)       ""
   #define CH_CLANLEADNAME(ch)   FALSE
   #define CH_CLANONENAME(ch)    FALSE
   #define CH_CLANTWONAME(ch)    FALSE
   #define CH_CLANLEADRANK(ch)   "Leader"
   #define CH_CLANONERANK(ch)    "First Officer"
   #define CH_CLANTWORANK(ch)    "Second Officer"
   #define I3NOTELL(ch)	 	(PRF_FLAGGED((ch), PRF_NOTELL))
#endif
