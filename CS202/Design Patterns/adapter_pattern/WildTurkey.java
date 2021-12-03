package adapter_pattern;

public class WildTurkey implements Turkey {
    public void fly() {
        System.out.println("Fly a short distance");
    }

    public void gobble() {
        System.out.println("Gobble");
    }
}