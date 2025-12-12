FROM ubuntu:24.04

RUN apt-get update && apt-get install -y g++ make

WORKDIR /app

COPY poisson_solver_serial/ .

RUN make

CMD ["./main"]
