package adapter_pattern;

public class DuckTestDrive {
    public static void main(String[] args) {
        MallardDuck mallardDuck = new MallardDuck();

        WildTurkey wildTurkey = new WildTurkey();
        Duck wildTurkeyAdapter = new TurkeyAdapter(wildTurkey, 3);

        Duck[] ducks = { mallardDuck, wildTurkeyAdapter };
        for (Duck duck : ducks) {
            testDuck(duck);
            System.out.println();
        }
    }

    private static void testDuck(Duck duck) {
        duck.quack();
        duck.fly();
        duck.swim();
    }
}