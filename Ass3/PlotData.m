%% TORSO
if exist('DataTorso','var')
    figure

    middlePoint=0.1/sqrt(2);
    P=[0.1,0;middlePoint,middlePoint;0,0.1;-middlePoint,middlePoint;-0.1,0;-middlePoint,-middlePoint;0,-0.1;middlePoint,-middlePoint];

    scatter(P(:,1),P(:,2),'filled')
    xlim([-0.15,0.15])
    ylim([-0.15,0.15])
    hold on
    plot(DataTorso.signals.values(:,1),DataTorso.signals.values(:,2),'color','r')

    xlabel('x'); 
    ylabel('y');
    title('Movement data of the torso');
end

%% WRIST
if exist('DataWrist','var')
    figure

    middlePoint=0.1/sqrt(2);
    P=[0.1,0;middlePoint,middlePoint;0,0.1;-middlePoint,middlePoint;-0.1,0;-middlePoint,-middlePoint;0,-0.1;middlePoint,-middlePoint];

    scatter(P(:,1),P(:,2),'filled')
    xlim([-0.15,0.15])
    ylim([-0.15,0.15])
    hold on
    plot(DataWrist.signals.values(:,1),DataWrist.signals.values(:,2),'color','r')

    xlabel('x'); 
    ylabel('y');
    title('Movement data of the wrist');
end
