# Use the gcc official docker image
FROM gcc:12.3.0

# Install valgrind for checking memory leaks
RUN apt-get update && apt-get install -y valgrind

# Copy all source files
COPY . /_shell/src

# Set the working directory
WORKDIR /_shell/src

# Compile the code
RUN gcc *.c -o my_shell

# Run the shell program
CMD ["./my_shell"]
