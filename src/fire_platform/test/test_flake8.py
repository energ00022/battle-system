import subprocess


def test_flake8():
    """Run flake8 on fire_platform source code."""
    result = subprocess.run(
        ["flake8", "src/fire_platform/fire_platform"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    assert result.returncode == 0, result.stdout
