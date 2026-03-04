import subprocess

def run_program():
    result = subprocess.run(
        ["./program.out"], capture_output=True, text=True, check=True
    )
    return result.stdout.strip().splitlines()

def test_checkutils_and_mathextras():
    output = run_program()
    assert "5 is odd" in output[0]
    assert "6 is even" in output [1]
    assert "Factorial(5) = 120" in output [2]
    print("It worked bitch")

if __name__ == "__main__":
    test_checkutils_and_mathextras()
