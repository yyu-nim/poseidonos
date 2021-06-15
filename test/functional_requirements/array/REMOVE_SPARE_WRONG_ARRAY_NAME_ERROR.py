#!/usr/bin/env python3
import subprocess
import os
import sys
sys.path.append("../")
sys.path.append("../../system/lib/")
sys.path.append("../volume/")
sys.path.append("../array/")

import json_parser
import pos
import cli
import api
import json
import MOUNT_ARRAY_BASIC
SPARE = MOUNT_ARRAY_BASIC.SPARE

def execute():
    MOUNT_ARRAY_BASIC.execute()
    out = cli.remove_device(SPARE, "wrong_array_name")
    return out

if __name__ == "__main__":
    api.clear_result(__file__)
    out = execute()
    ret = api.set_result_by_code_ne(out, 0, __file__)
    pos.kill_pos()
    exit(ret)