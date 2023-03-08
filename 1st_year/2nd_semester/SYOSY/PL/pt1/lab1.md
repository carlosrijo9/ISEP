# System of Systems - Assignment 1
## Overview

MQTT (originally an initialism of MQ Telemetry Transport) is a lightweight, publish-subscribe, machine to machine network protocol for message queue/message queuing service. It is designed for connections with remote locations that have devices with resource constraints or limited network bandwidth. It must run over a transport protocol that provides ordered, lossless, bi-directional connections—typically, TCP/IP. It is an open OASIS standard and an ISO recommendation (ISO/IEC 20922).

In this LAB you will be learning about MQTT, setting up a test environment and exploring,
hands-on, an MQTT implementation. Particularly, you will be looking into the MQTT QoS levels and connection persistence settings.

At the end you will be asked to write a small (max. 2 pages) report on a topic related to MQTT.

## Answers
### Test 1
Subscriber didn't receive any messages since it was launched without a persistent connection and with QoS0. Whitch means that the message sent by the publisher will be deleted after it is sent and both the client and broker take no additional steps to acknowledge delivery (fire and forget).

### Test 2
Subscriber didn't receive any message because of QoS0 (even with persistence)

### Test 3

### Test 4

### Test 5

## Additional Documents
- ./SYOSY-LAB1.pdf
- ./report/main.pdf

## References