package adapter_pattern;

public class MallardDuck implements Duck {
    public void fly() {
        System.out.println("Flying");
    }

    public void quack() {
        System.out.println("Quack");
    }

    public void swim() {
        System.out.println("Swimming");
    }
}