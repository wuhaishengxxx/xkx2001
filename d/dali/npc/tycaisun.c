//Cracked by Roath
// tycaisun.c ̨�Ĳ�����

inherit NPC;

void create()
{
	set_name("������", ({ "caisun ren", "ren", "woman" }) );
	set("long", "һ��¬¹��������̨�ĸ�Ů�������˸��������һ�ѿ��񵶣���������\n");

	set("age", 25);
	set("gender", "Ů��");
	set("dalivictim",1);

	set("str", 25);
	set("cor", 25);

    set("combat_exp", 5000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/d/dali/npc/obj/kandao.c")->wield();
	carry_object("/d/dali/npc/obj/tytongqun.c")->wear();
	carry_object("/d/dali/npc/obj/zhutong.c");
}