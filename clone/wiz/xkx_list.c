//Cracked by Roath
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"�����з��ư�"NOR, ({"xkx list"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������ҵķ��ư񣬿�����(readlist)���鿴��\n");
                set("unit", "��");
                set("value", 1000000);
        }
}

void init()
{
    add_action("do_readlist", "readlist");
    add_action("do_sell", "sell");
}

int do_readlist(string arg)
{
	mapping *lists;
	int k, num;
		
	lists = this_object()->query("data");
	
	if( !lists ) return notify_fail("�����������з��ư���͵���İɣ�\n");
	
	num = sizeof(lists);
	if ( num > 100 ) num = 100;
	
	write("�����з��ư�\n");
	for(int i = 0; i < num; i++)
	{
		k = i+1;
		write("��"+ chinese_number(k) + "����" + lists[i]["name"] + "(" + lists[i]["id"] + "): ���� " + lists[i]["exp"] + "�����䣺" + chinese_number(lists[i]["age"]) + "�ꡣ\n");
	}
	return 1;
}

int do_sell(string arg)
{
	object me = this_player();
	object ob = this_object();
	
	if(arg == "xkx list" && me->query("env/wiz_tester") != 1) {
		ob->set("value", 100);
		call_out("change_value", 1, me, ob);
	}
	return 0;
}

void change_value(object me, object ob)
{
	if(me && !present(ob, me)) {
		tell_object(me, "��ϧ���ֵ������з��ư�ֵֻ��ʮ��ͭǮ��\n");
		ob->set("value", 1000000);
	}
}