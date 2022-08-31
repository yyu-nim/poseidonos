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
import pos_util
import cli
import api
import json
import MOUNT_VOL_MAX_SIZE
import fio
import time
ARRAYNAME = MOUNT_VOL_MAX_SIZE.ARRAYNAME

def execute():
    MOUNT_VOL_MAX_SIZE.execute()
    cli.start_telemetry()
    time_50m = 60 * 50
    time_48h = 3600 * 48
    #sequentialwrite
    print("sequential write begin")
    fio_proc = fio.start_fio(0, time_50m)
    fio.wait_fio(fio_proc)
    print("sequential write end")
    print("mixed i/o begin")
    fio_proc = fio.start_fio(0, time_48h, "randrw")
    fio.wait_fio(fio_proc)
    print("mixed i/o end")

if __name__ == "__main__":
    if len(sys.argv) >= 2:
        pos.set_addr(sys.argv[1])
    api.clear_result(__file__)
    execute()