package adapter_pattern;

public class OstrichAdapter implements Duck {
    private Ostrich ostrich;

    public OstrichAdapter(Ostrich ostrich) {
        this.ostrich = ostrich;
    }

    public void fly() {
        System.out.println("Can't fly");
    }

    public void quack() {
        ostrich.boom();
    }

    public void swim() {
        System.out.println("Can't swim");
    }
}