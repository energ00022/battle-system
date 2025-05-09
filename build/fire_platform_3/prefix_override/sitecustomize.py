import sys
if sys.prefix == '/home/willi/battle_ws/.ci-test-env':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/willi/battle_ws/install/fire_platform_3'
