//Cracked by Roath
// Room: mjroom place to play mj 
// Mantian 05/12/2001
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", YEL"�ƾ�Է"NOR);
	set("long", @LONG
�˼仨�����ã�һ��������;��þ�����ˬ�����������⿪��������ƾգ�
һ�ŵ���ɫ�Ĵ���ʯ��������һ����ֲ�������д�Ŷ����ϣ������������ϰ���
һ���齫�����ܵ�С�ʽ��Զ������֡�ǽ�ϵļƷְ�(Board)����ɽǼľ�����ơ�
LONG);
	set("exits", ([
		"east" : __DIR__"mjroom",
		]));
	set("objects", ([
		__DIR__"npc/mjxiaosi" : 1,
		__DIR__"obj/ytable" : 1,
		]));
	set("item_desc", ([
		"board": YEL"    һ����ɽǼľ�����ƵļƷְ壬��������������ƾ�\n"
					"�ķ��������һ��mjscore����ѯ�Լ��ķ�����mjscore <ip>\n"
					"����ĳ�˵ķ�����mjscore -l��ȫ�������ϡ�\n"NOR,
		]) );
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
	set("cost", 3);
	setup();
}
void init()
{
	add_action("do_practice", "kill");
	add_action("do_practice", "practice");
	add_action("do_practice", "lian");
	add_action("do_practice", "dazuo");
	add_action("do_practice", "exercise");
	add_action("do_practice", "tuna");
	add_action("do_practice", "respirate");
	add_action("do_practice", "quit");
}
int do_practice()
{
	if (query_verb()=="quit") write("���޷����齫�����뿪��Ϸ����\n");
	if (query_verb()=="kill") write("�������������齫�����Ǵ�ܡ�\n");
    if (query_verb()=="exercise") write("�����������齫�����Ǵ�����\n");
    if (query_verb()=="dazuo") write("�����������齫�����Ǵ�����\n");
    if (query_verb()=="lian") write("�����������齫������������\n");
    if (query_verb()=="practice") write("�����������齫������������\n");
    if (query_verb()=="respirate") write("�����������齫���������š�\n");
    if (query_verb()=="tuna") write("�����������齫���������š�\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("���齫��"))	return notify_fail("���ƴ�һ�룬����ȥ�ģ�\n");
	if (this_object()->query_temp("mjstart") && dir == "east")	return notify_fail("�ƾֽ�������������ȥ��Ӱ�����ˣ�������������߰ɡ�\n");
	return ::valid_leave(me, dir);
}