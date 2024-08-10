#!/bin/bash

# Navigate to the build directory and run the daemon
cd /workspaces/IPC_COM/build
# echo "Starting daemon..."
# ./daemon &

# Allow some time for the daemon to start (optional, adjust if necessary)
sleep 1

# Use expect to automate the input for offer_service
echo "Starting offer_service..."
./offer_service &
expect <<EOF
expect "Enter service name to offer:"
send "ipc\r"
expect eof
EOF

# Allow some time for offer_service to complete its initialization
sleep 1

# Run the find_service
echo "Starting find_service..."
./find_service &

# Wait for all background processes to finish
wait

echo "All services have been executed."
