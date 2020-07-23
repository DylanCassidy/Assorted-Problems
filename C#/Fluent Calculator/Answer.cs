using Console = System.Console;

public class MainClass
{
	public static void Main(string[] args)
	{
		Console.WriteLine(Calc().New().One().Plus().Two());
		Console.WriteLine(Calc().New().Five().Minus().Six());
		Console.WriteLine(Calc().New().Seven().Times().Two());
		Console.WriteLine(Calc().New().Nine().DividedBy().Three());
	}

	public static Calculator Calc() { return new Calculator(); }
}

public class Calculator
{
	public Operation New() { return new Operation(); }
}

public class Operation
{
	public int Zero() { return 0; }
	public int One() { return 1; }
	public int Two() { return 2; }
	public int Three() { return 3; }
	public int Four() { return 4; }
	public int Five() { return 5; }
	public int Six() { return 6; }
	public int Seven() { return 7; }
	public int Eight() { return 8; }
	public int Nine() { return 9; }
}

public static class IntExtensions
{
	public static PlusFunction Plus(this int leftHandValue) { return new PlusFunction(leftHandValue); }
	public static MinusFunction Minus(this int leftHandValue) { return new MinusFunction(leftHandValue); }
	public static TimesFunction Times(this int leftHandValue) { return new TimesFunction(leftHandValue); }
	public static DividedByFunction DividedBy(this int leftHandValue) { return new DividedByFunction(leftHandValue); }
}

public abstract class Function
{
	protected readonly int _leftHandValue;

	public Function(int leftHandValue)
	{
		_leftHandValue = leftHandValue;
	}

	public abstract int Execute(int rightHandValue);
}

public static class FunctionExtensions
{
	public static int Zero(this Function function) { return function.Execute(0); }
	public static int One(this Function function) { return function.Execute(1); }
	public static int Two(this Function function) { return function.Execute(2); }
	public static int Three(this Function function) { return function.Execute(3); }
	public static int Four(this Function function) { return function.Execute(4); }
	public static int Five(this Function function) { return function.Execute(5); }
	public static int Six(this Function function) { return function.Execute(6); }
	public static int Seven(this Function function) { return function.Execute(7); }
	public static int Eight(this Function function) { return function.Execute(8); }
	public static int Nine(this Function function) { return function.Execute(9); }
}

public class PlusFunction : Function
{
	public PlusFunction(int leftHandValue) : base(leftHandValue) { }

	public override int Execute(int rightHandValue) { return _leftHandValue + rightHandValue; }
}

public class MinusFunction : Function
{
	public MinusFunction(int leftHandValue) : base(leftHandValue) { }

	public override int Execute(int rightHandValue) { return _leftHandValue - rightHandValue; }
}

public class TimesFunction : Function
{
	public TimesFunction(int leftHandValue) : base(leftHandValue) { }

	public override int Execute(int rightHandValue) { return _leftHandValue * rightHandValue; }
}

public class DividedByFunction : Function
{
	public DividedByFunction(int leftHandValue) : base(leftHandValue) { }

	public override int Execute(int rightHandValue) { return _leftHandValue / rightHandValue; }
}