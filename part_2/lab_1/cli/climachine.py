from transitions import Machine
from typing import List, Dict, Any


class CLIMachine:

    states: List[str] = [
        'initial',
        'logged_in',
        'pin_creation',
        'balance_check',
        'card_creation',
        'status_change',
        'card_blocking',
        'exit'
    ]

    def __init__(self, cli) -> None:
        self.cli = cli
        self.machine = Machine(
            model=self,
            states=self.states,
            initial='initial'
        )
        self.machine.add_transitions([
            {
                'trigger': 'login',
                'source': 'initial',
                'dest': 'logged_in'
            },
            {
                'trigger': 'create_pin',
                'source': 'logged_in',
                'dest': 'pin_creation'
            },
            {
                'trigger': 'check_balance',
                'source': 'logged_in',
                'dest': 'balance_check'
            },
            {
                'trigger': 'create_card',
                'source': 'logged_in',
                'dest': 'card_creation'
            },
            {
                'trigger': 'change_status',
                'source': 'logged_in',
                'dest': 'status_change'
            },
            {
                'trigger': 'block_card',
                'source': 'logged_in',
                'dest': 'card_blocking'
            },
            {
                'trigger': 'return_to_menu',
                'source': '*',
                'dest': 'logged_in'
            },
            {
                'trigger': 'logout',
                'source': '*',
                'dest': 'initial'
            },
            {
                'trigger': 'quit',
                'source': '*',
                'dest': 'exit'
            }
        ])

    def on_enter_logged_in(self) -> None:
        self.cli.show_main_menu()

    def on_enter_initial(self) -> None:
        self.cli.show_initial_menu()