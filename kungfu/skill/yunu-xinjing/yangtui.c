//Cracked by Kafei
// lifeheal.c

#include <ansi.h>
void over(object,object);
void over1(object,object);
void over2(object,object);
void over3(object,object);
void over4(object,object);
void over5(object,object);
void over6(object,object);
void over7(object,object);
void over8(object,object);
int exert(object me, object target)
{
	object obj, old_target;
        object *ob;
        mapping myfam;

	if( !target )
		return notify_fail("��Ҫ������Ϊ�����ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷������ˣ�������ô��\n");

	if( !living(target) )
		return notify_fail(target->name() + "�Ѿ��޷������˹������ˡ�\n"); 

	if( !userp(target) )
		return notify_fail("ֻ�������֮�以��������Ů�ľ���\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "��Ĺ��") )
                  return notify_fail("ֻ�й�Ĺ����֮�����������Ů�ľ����ޡ�\n");

//	if( me->query_temp("gumu/yangtui"))
//		return notify_fail("���Ѿ����˹������ˡ�\n");

        if( me->query("gender") =="����" )
                return notify_fail("���Ѿ���������Ů�ľ��е����������仯�ˡ�\n");

	if( (int)me->query_skill("yunu-xinjing", 1) < 20 )
		return notify_fail("�����Ů�ľ����̫�ͣ��޷���������������\n");

	if( (int)me->query_skill("yunu-xinjing", 1) < (int)target->query_skill("yunu-xinjing", 1) / 2 )
		return notify_fail("�����Ů�ľ����̫�ͣ��޷������Է�������\n");

        if ( me->query_skill_mapped("force") != "yunu-xinjing")
                return notify_fail("��û�м�����Ů�ľ����ڹ��ϣ�\n"); 

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

        if( target->query_condition("huaiyun") > 0)
                return notify_fail("�Է��ڻ����У�ǿ���˹���ϰ���˼�̥����\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi")  )
		return notify_fail( target->name() +"�Ѿ����ˣ����ܲ�����������𵴣�\n");

	if(target==me)	return notify_fail("�㲻��Ϊ�Լ��˹�������\n");

	if( userp(target) && (object)target->query_temp("pending/yunu-xinjing")!=me ) {
		message_vision("\n$N����$n˵�������Ѿ�׼�����˹���ϰ��Ů�ľ���\n\n", me, target);
		if( objectp(old_target = me->query_temp("pending/yunu-xinjing")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����������ͷ��\n" NOR);
		me->set_temp("pending/yunu-xinjing", target);
		tell_object(target, YEL "�����Ը��ͶԷ�ͬʱ�˹������������" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� yun yinjin ָ�\n" NOR);
		write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܿ�ʼ������\n" NOR);
		return 1;
	}

	else {
		message_vision("\n$n����ϰ��Ů�ľ��Ŀھ�����˵��һ�Σ�$N���˵��ͷ��ϥ����׼���˹���\n\n", me, target);
		target->delete_temp("pending/yunu-xinjing");
		me->set_temp("gumu/yangtui", 1);
		me->start_busy(10);
		call_out("over", 3, me,target);
	} 
	return 1;
}
void over(object me,object obj)
{
        message_vision(WHT"$N���˵������������$n������֡�\n"NOR,me,obj);

	if(me->query("qi")<99||me->query("jing")<99) {
                        message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�����������͸֧�����ˡ�\n"NOR,me);
			me->receive_damage("qi", 60, "����͸֧��������");
                        me->unconcious();
	}
	if(obj->query("qi")<99||obj->query("jing")<99) {
                        message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�����������͸֧�����ˡ�\n"NOR,obj);
			obj->receive_damage("qi", 60, "����͸֧��������");
                        obj->unconcious();
	}
				me->start_busy(30);
				obj->start_busy(30);
                                call_out("over1", 30, me,obj);
}
void over1(object me,object obj)
{
                message_vision(HIY "$N����������������$n������������������������������$N
������������һ�����죬������ʼ����$n��\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over2", 30, me,obj);
}

void over2(object me,object obj)
{
                message_vision(HIY "$N��������������������������ͬʱҲ���е���$n���ڣ����
������$n���ڹ��Ϲ��������裬��ʮ����¥��ѭ����ȫ����Ѩ��\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(03);
                call_out("over3", 30, me,obj);
}

void over3(object me,object obj)
{
                message_vision(HIR "$N��$n�������ڶԷ����������߲�������ת��Ϣ��Լ��һ�ٷ�
�Ĺ���$N��$n���������ޱȣ���Ѫ���ڣ��������¡�\n"NOR,me,obj);

/*
		if( objectp(cloth = present(arg, me)) || cloth->query("equipped")){
                message_vision(HIR "$Nֻ���û������Ȳ�����ԭ�������ϻ���������������������ʱ��ɢ�������ڡ�\n"NOR,me);
                message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�\n"NOR,me);
		me->receive_damage("qi", 1000, "�����߻���ħ����");
		me->receive_damage("jing", 1000, "�����߻���ħ����");
		return 1;
		}

		if( objectp(cloth = present(arg, obj)) || cloth->query("equipped")){
                message_vision(HIR "$Nֻ���û������Ȳ�����ԭ�������ϻ���������������������ʱ��ɢ�������ڡ�\n"NOR,obj);
                message_vision(HIR "$NͻȻ������Ѫ���ε��ڵء�\n"NOR,obj);
		obj->receive_damage("qi", 1000, "�����߻���ħ����");
		obj->receive_damage("jing", 1000, "�����߻���ħ����");
		return 1;
		}
*/
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over4", 30, me,obj);
}

void over4(object me,object obj)
{
                message_vision(HIW "�ֹ���һ�����ֻ������ȫ���������ڣ�ͷ������˿˿������
���������������Ǹ߳�����Χ�������ơ�\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over5", 30, me,obj);
}
void over5(object me,object obj)
{
                message_vision(HIM "�ٹ�һ�������������������ɢ��$N��������������������
����ɢ���ζ�����֮�С�\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over6", 30, me,obj);
}
void over6(object me,object obj)
{
                message_vision(MAG "$n��Ȼ�����˹��������䲻��ղ��ǰ�����죬��������
üͷ��������ʱ����������á�\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over7", 30, me,obj);
}
void over7(object me,object obj)
{
                message_vision(YEL "����һյ��Ĺ���$n���΢̧�������³�һ�ڰ��������
�����������������������ڵ���֮�У��˹���ֹ��\n"NOR,me,obj);
		me->start_busy(30);
		obj->start_busy(30);
                call_out("over8", 30, me,obj);
}
void over8(object me,object obj)
{
                message_vision("��ʱ���������������Ѿ���ɢȥ��$n���������ۣ���$N����һЦ��\n",me,obj);

		me->improve_skill("force", me->query_con()+random(me->query_skill("yunu-xinjing", 1))*40);
		me->improve_skill("yunu-xinjing", me->query_con()+random(me->query_skill("force", 1))*40);
		me->delete_temp("gumu/yangtui");
		me->start_busy(30);
		obj->start_busy(30);

		if (obj->query_skill("yunu-xinjing", 1) < 61){
		obj->set("request/yunu",obj->query_skill("yunu-xinjing", 1)/20+1);
		}

		if (me->query_skill("yunu-xinjing", 1) < 120 && obj->query_skill("yunu-xinjing", 1) > 61){
		obj->set("request/yunu",obj->query_skill("yunu-xinjing", 1)/10+1);
		}
		if (me->query_skill("yunu-xinjing", 1) > 120){
		obj->set("request/yunu", obj->query_skill("yunu-xinjing", 1)/5+1);
		}
}