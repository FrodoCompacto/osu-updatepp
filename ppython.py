import urllib2
import json
import argparse

from time import sleep

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('playerid', metavar='PLAYERID')
    parser.add_argument('output_file', metavar='OUTPUT')

    return parser.parse_args()

args=parse_args()

while True:
    req = urllib2.Request("https://osu.ppy.sh/api/get_user?k=c78156f8a36708af0ac5f6d4d9b5f75ba0b2c2d9&u={}&m=0&type=id".format(args.playerid))
    opener = urllib2.build_opener()
    f = opener.open(req)
    myjson = json.loads(f.read())
    try:
        with open(args.output_file, 'w') as myoutput:
            myoutput.write("{pp_country_rank}".format(pp_country_rank=myjson[0]['pp_country_rank']))
    except FileNotFoundError as e:
        print("Couldn't find file '%s'" % e)
    sleep(5)
