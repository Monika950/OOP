package org.elsys.bg.calculator.postfix;

import java.util.Stack;

public class Calculator<T extends Number> {
    Stack<T> numbers;

    public Calculator() {

    }

    public int push (T value)
    {
        numbers.push(value);
        return numbers.size();
    }

    private T doubleToT(double val)
    {
        return (T) Double.valueOf(val);
    }

    public T peek()
    {
        return numbers.peek();//?
    }

    private int _push(double val)
    {
        return push(doubleToT(val));
    }

    public int plus()
    {
        T first = numbers.pop();
        T second = numbers.pop();
        return _push(first.doubleValue() + second.doubleValue());
    }

    public int multiply()
    {
        T first = numbers.pop();
        T second = numbers.pop();
        return _push(first.doubleValue() * second.doubleValue());
    }

    public int minus()
    {
        T first = numbers.pop();
        T second = numbers.pop();
        return _push(first.doubleValue()- second.doubleValue());//fix
    }

    public int negate()
    {
        if(numbers.isEmpty())
        {
            return -1;
        }
        T first = numbers.pop();
        return _push(first.doubleValue()*-1);
    }
}
