"""Banking system main entry point."""

from cli import CLI


def main():
    """Start the banking system."""
    cli = CLI()
    cli.start()


if __name__ == "__main__":
    main()