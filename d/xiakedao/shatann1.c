//Cracked by Roath
// Dong 1/9/98
// modifiedy by aln 5 / 98
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "ɳ̲");
    	set("long", @LONG
ɳ̲���Ǻܴ󣬰װ׵�ϸɳ��������౴�ǣ����˳����������
��������ʮ�ֺÿ���ɳ̲�ı�����һ�Ÿ߸ߵ�Ҭ���������ϻ����ż�
ֻҬ�ӡ�һ�󺣷紵����Ҭ�������ҡ���ţ�Ҭ�Ӻ����Ҫ��������
�ġ�ż���ɼ����СС�ĺ���������ȥ��
LONG
    	);

    	set("exits", ([
		       "east" : __DIR__"shatann2",
		       "southwest" : __DIR__"haibian1",
		       ]));
    	set("outdoors", "xiakedao");
	set("objects", ([ 
			 __DIR__"npc/haigui_s" : 1, 
			 ]));

    	setup();
}

