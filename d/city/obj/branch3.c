//Cracked by Roath
// branch3.c
// Jay 7/4/96
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
    set_name(YEL"������"NOR, ({"shuzhi", "zhi", "branch"}));
    set_weight(1000+random(2000)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ���۶ϵĴ����ɡ�\n");
	set("unit","��");
	set("wield_msg","$N����һ���������������С�\n");
	set("material", "wood");
    }
    init_staff(random(2));

    setup();
}