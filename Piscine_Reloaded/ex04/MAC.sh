#!/bin/bash
ifconfig | grep "^\tether*" | sed 's/	ether //g' | sed 's/ //g'
