//Cracked by Roath
// /clone/board/gaibang_r.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ݳ�������ⱨ��", ({ "report" }) );
	set("location", "/d/gaibang/gbxiaowu");
	set("board_id", "gaibang_r");
	set("long", "����һ����ؤ����ӽ�����Ϣ�����԰塣\n" );
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}
