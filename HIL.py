import random
import subprocess

def simulate_hardware():
    """Simulate real-time hardware sensor data."""
    return {
        "ambient_light": random.uniform(0, 100),
        "proximity": random.uniform(0, 50),
    }

def test_lighting_control():
    for _ in range(10):
        # Simulate hardware inputs
        sensors = simulate_hardware()
        ambient_light = sensors["ambient_light"]
        proximity = sensors["proximity"]

        # Pass inputs to C program
        process = subprocess.run(
            ['./lighting_control'], 
            input=f'{ambient_light} {proximity}\n',
            text=True, capture_output=True
        )

        # Print output
        print(process.stdout.strip())

if __name__ == "__main__":
    test_lighting_control()
