% Initialize thresholds
ambient_threshold = 30; % lux
proximity_threshold = 10; % meters

% Simulation loop
for t = 1:100
    % Generate random sensor values
    ambient_light = randi([0, 100]); % Random ambient light between 0 and 100 lux
    proximity = randi([0, 50]); % Random proximity between 0 and 50 meters

    % Control logic
    headlights = ambient_light < ambient_threshold;
    high_beams = headlights && (proximity > proximity_threshold);

    % Display real-time output
    fprintf(['Time: %d |' ...
            'Ambient: %d lux |' ...
            'Proximity: %d meters |' ...
            'Headlights: %s |' ...
            'High Beams: %s\n'], ...
            t, ...
            ambient_light, ...
            proximity, ...
            bool_to_string(headlights), ...
            bool_to_string(high_beams));
    
    % Simulate real-time behavior
    pause(0.1);
end

% Helper function to convert boolean to string
function str = bool_to_string(value)
    if value
        str = 'ON';
    else
        str = 'OFF';
    end
end