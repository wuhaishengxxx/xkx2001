//Cracked by Roath
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("ͺ����",({ "tubi weng","weng" }) );
        set("gender", "����");
        set("age", 45);
	set("long",
		"���������֣�ͷ��ͺ���͹⻬����"
		"һ��ͷ��Ҳû�У������϶���ī����\n");
       // set("nickname","");
        set("title","÷ׯ��ׯ��");
        set("combat_exp", 80000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 80);
	set_skill("force",80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("club",80);

	set("max_neili",450);
	set("neili",450);
	set("jiali",40);


        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/panguanbi")->wield();
}


#include "mzkill.h"
