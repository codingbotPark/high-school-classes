package kr.hs.dgsw.java.dept23.d0428;

// �߻��̶� �繰�̳� ǥ��(����)�� � ���������뼺�������� �����Ͽ� �װ��� ����(����)�Ͽ� �ľ��ϴ� ��
// �߻� �۷����� abstract�� �߰��ϸ� �ȴ�
public abstract class Animal {
	public abstract String getName();
	
	// �߻� �޼ҵ�� ����� �ش�
	public abstract String makeSound();
	// �߻�޼ҵ�� �̸��� ������ �ִ�
	// ȣ�⸸ �س��� ��ӹ��� ������ ������ �ȴ�
	
	
	public void move() {
		System.out.printf("%s ��(��) %s �Ҹ��� ���� �޷����ϴ�",getName(),makeSound());
	}
	
	public static void main(String[] args) {
		// �߻� Ŭ������ �ٷ� ��ü�� ���� �� ����
		// Animal animal = new Animal();
		
		// ��� �߻� Ŭ������ ��ӹ��� �ڽ����κ��� ��ü�� ���� �� �ִ�
		Animal animal = new Horse();
		animal.move();
	}
}
