package kr.hs.dgsw.java.dept23.d0421;

public class Zoo {
//	public void breed(Pig pig) {
//		System.out.printf("%s�� %s��ϴ�. \n",pig.getName(),pig.getSound());
//	}
//	public void breed(Duck duck) {
//		System.out.printf("%s�� %s��ϴ�. \n",duck.getName(),duck.getSound());
//	}
	
	// ���� ��ó�� ������ Ÿ�Կ� �´� breed�� �������� ������
	// ��� ������ �θ��� Ÿ���� �ޱ� ������
	// animal�̶�� ��ü�� ��ӹ޾� ��������ν� ��Ȱ���Ų��
	public void breed(Animal animal) {
		System.out.printf("%s�� %s��ϴ�\n", animal.getName(),animal.getSound());
	}
	public static void main(String[] args) {
		Zoo zoo = new Zoo();
		
		Pig pig = new Pig();
		zoo.breed(pig);
		
		Duck duck = new Duck();
		zoo.breed(duck);
		
		Cat cat = new Cat();
		zoo.breed(cat);
	}
	
	// �̷� ����� ������ Ȱ���ؼ� ������ ����� ��
	// ���� �κ��� ���� �� �� ����� ����ؼ� ȿ�������� �ذ��� �� �ִ�
}
