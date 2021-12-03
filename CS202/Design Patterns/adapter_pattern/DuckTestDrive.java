package adapter_pattern;

public class DuckTestDrive {
    public static void main(String[] args) {
        MallardDuck mallardDuck = new MallardDuck();

        WildTurkey wildTurkey = new WildTurkey();
        Duck wildTurkeyAdapter = new TurkeyAdapter(wildTurkey, 3);

        Ostrich ostrich = new Ostrich();
        Duck ostrichAdapter = new OstrichAdapter(ostrich);

        Duck[] ducks = { mallardDuck, wildTurkeyAdapter, ostrichAdapter };
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