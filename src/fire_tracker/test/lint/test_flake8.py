import subprocess


def test_flake8():
    """Run flake8 on fire_tracker source code."""
    result = subprocess.run(
        ["flake8", "src/fire_tracker/fire_tracker"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    assert result.returncode == 0, result.stdout
