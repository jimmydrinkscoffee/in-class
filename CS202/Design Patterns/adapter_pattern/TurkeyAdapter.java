package adapter_pattern;

public class TurkeyAdapter implements Duck {
    private Turkey turkey;
    private int flyingTime;

    public TurkeyAdapter(Turkey turkey, int flyingTime) {
        this.turkey = turkey;
        this.flyingTime = flyingTime;
    }

    public void fly() {
        for (int i = 0; i < flyingTime; ++i)
            turkey.fly();
    }

    public void quack() {
        turkey.gobble();
    }

    public void swim() {
        System.out.println("Can't swim");
    }
}