#!/usr/bin/env python3

import argparse
import logging

from rpi_rf import RFDevice
from flask import request
from flask_api import FlaskAPI

def sendcode( code ):
    rfdevice = RFDevice(17)
    rfdevice.enable_tx()

    protocol = 1 
    pulselength = 350 

    rfdevice.tx_code(code, protocol, pulselength)
    rfdevice.cleanup()
    return



app = FlaskAPI(__name__)

@app.route('/', methods=["GET"])
def api_root():
    return {
        "url": request.url + "springkle/( 1111(on) | 9999 (off) )/"
            }

@app.route('/springkle/<code>', methods=["GET", "POST"])
def api_leds_control(code):
    if request.method == "POST":
        sendcode(int(code))
    
    return code

if __name__ == "__main__":
    app.run()
