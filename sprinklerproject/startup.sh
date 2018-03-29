#!/bin/sh

export FLASK_APP=springkelapp.py

nohup sudo -E flask run --host=0.0.0.0 --port=8001 >> springkle.log &
