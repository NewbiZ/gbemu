#!/usr/bin/env python

import BeautifulSoup as bs
import requests
import json

# Retrieve the webpage containing instruction set
url = 'http://www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html'
html = requests.get(url).text

soup = bs.BeautifulSoup(html)

table_unprefixed, table_cbprefixed = soup.findAll('table')[:2]

def parse_table(table):
    opcodes = {}
    # For each row (LS 4 bits), skipping the header
    LSb = 0
    for row in table.findAll('tr')[1:]:
        MSb = 0
        # For each col (MS 4 bits), skipping the header
        for col in row.findAll('td')[1:]:
            # Undefined opcodes, skip them
            if len(col)==1 and col.text=='&nbsp;':
                continue

            opcode_meta = {}

            values = col.contents[0].split(' ')
            opcode_meta['mnemonic']= values[0]
            
            # This opcode has operands
            if len(values)>1:
                values = values[1].split(',')
                opcode_meta['operand_count'] = len(values)
                opcode_meta['operand1'] = values[0]
                # This opcode has 2 operands
                if len(values)>1:
                    opcode_meta['operand2'] = values[1]
            # This opcode has no operand
            else:
                opcode_meta['operand_count'] = 0

            # Retrieve bytes and cycle count
            values = col.contents[2].split('&nbsp;&nbsp;')
            opcode_meta['bytes'] = int(values[0])
            # Some instruction have different cycle count depending on whether actions
            # were taken or not (jumps/calls/rets)
            opcode_meta['cycles'] = [int(x) for x in values[1].split('/')]

            opcode_meta['flags_ZHNC'] = col.contents[4].split(' ')

            opcodes[hex(LSb<<4 | MSb)] = opcode_meta
            MSb += 1
        LSb += 1
    return opcodes

opcodes = {
    'unprefixed': parse_table(table_unprefixed),
    'cbprefixed': parse_table(table_cbprefixed),
}

print json.dumps(opcodes, indent=2)
