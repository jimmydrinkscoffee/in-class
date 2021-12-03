package adapter_pattern;

public class TurkeyAdapter implements Duck {
    Turkey turkey;
    int flyingTime;

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
        throw new UnsupportedOperationException();
    }
}