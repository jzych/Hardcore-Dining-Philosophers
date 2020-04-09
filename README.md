# Hardcore-Dining-Philosophers

[![Build Status](https://travis-ci.org/jzych/Hardcore-Dining-Philosophers.svg?branch=master)](https://travis-ci.org/jzych/Hardcore-Dining-Philosophers)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/4c22a002fc354098b0972e5a7297a608)](https://www.codacy.com/manual/jzych/Hardcore-Dining-Philosophers?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jzych/Hardcore-Dining-Philosophers&amp;utm_campaign=Badge_Grade)

Extended version of Dining Philosopher problem

## 1.0 Architecture

![Architecture diagram](doc/main_diagram.png)

*CTable* - contains two vectors of philosophers and forks.
It is responsible for init and end.

CPhilosooher - A thread with life-cycle of philosopher function.
It contains reference to its forks ie. "F0-F1".
This class writes its activity to CLog.
It asks CWaiter if can eat at specified (current) time.

*CFork* - fork representation.

*CLog* - log (queue) with philosophers activities.

*CoutputConsole* - class reponsible for display log on second console.

*CBook* - class with philosophers considerations.

*Consideration* - structure with philosopher consideration.
