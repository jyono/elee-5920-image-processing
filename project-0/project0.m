% part1
% mesh
% Set the colormap to gray. Default behavior is RBG spectrum.
colormap('gray')
% Create a 1x256 vector [0,1,2,... n = 255]
z = 0:255;
% Turn the vector into a 2d array 256x256 where rows are copied from the original
Z = meshgrid(z);
% Divide each element by 8 and simulate integer division by rounding to floor
Z = floor(Z/8);
% Plot
mesh(Z);

% surf
% Set the colormap to gray. Default behavior is RBG spectrum.
colormap('gray')
% Create a 1x256 vector [0,1,2,... n = 255]
z = 0:255;
% Turn the vector into a 2d array 256x256 where rows are copied from the original
Z = meshgrid(z);
% Divide each element by 8 and simulate integer division by rounding to floor
Z = floor(Z/8);
% Plot and set EdgeColor to none to override default behavior
surf(Z, 'EdgeColor','none');

%image
% Set the colormap to gray. Default behavior is RBG spectrum.
colormap('gray')
% Create a 1x256 vector [0,1,2,... n = 255]
c = 0:255;
% Turn the vector into a 2d array 256x256 where rows are copied from the original
C = meshgrid(c);
% Divide each element by 8 and simulate integer division by rounding to floor
C = floor(C/8);
% Plot and override default behavior to show scaling.
imagesc(C, 'CDataMapping','scaled' )


% part2
% Create a 1x256 vector [0,1,2,... n = 255]
x = 0:255;
% Create a 1x256 vector [0,1,2,... n = 255]
y = 0:255;
% Turn the vectors into 2d arrays 256x256 where rows are copied from the originals
[X,Y] = meshgrid(x,y);
% Apply the formula for 2d gaussian distribution
Z = exp(-((X-127).^2+(Y-127).^2)/(2*(10.^2)));
Z = Z * 255;
% Plot
mesh(X,Y,Z)