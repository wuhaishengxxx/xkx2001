//Cracked by Roath
//����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"la rou","rou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������Ĵ�����\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 7);
                set("food_supply", 50);
        }
}
