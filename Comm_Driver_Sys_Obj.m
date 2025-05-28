classdef Comm_Driver_Sys_Obj < matlab.System & coder.ExternalDependency
    %
    % System object template for a sink block.
    % 
    % This template includes most, but not all, possible properties,
    % attributes, and methods that you can implement for a System object in
    % Simulink.
    %
    % NOTE: When renaming the class name Sink, the file name and
    % constructor name must be updated to use the class name.
    %
    
    % Copyright 2016-2024 The MathWorks, Inc.
    %#codegen
    %#ok<*EMCA>
    
    properties
        % Public, tunable properties.
    end
    
    properties (Nontunable)
        % Public, non-tunable properties.
    end
    
    properties (Access = private)
        % Pre-computed constants.
    end
    
    methods
        % Constructor
        function obj = Comm_Driver_Sys_Obj(varargin)
            % Support name-value pair arguments when constructing the object.
            setProperties(obj,nargin,varargin{:});
        end
    end
    
    methods (Access=protected)
        function setupImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation setup code here
            else
                % Call C-function implementing device initialization
                coder.cinclude('Comm_Driver.h');
                coder.ceval('Comm_Driver_Init');
            end
        end
        
        function [txBuffer,debug] = stepImpl(obj,eulerAnglesTx,bodyRatesTx,posTx)  %#ok<INUSD>
            txBuffer = zeros(33,1,'uint8');
            debug = zeros(1,1,'single');
            if isempty(coder.target)
                % Place simulation output code here 
            else
                % Call C-function implementing device output
               debug = coder.ceval('Comm_Driver_Step',eulerAnglesTx,bodyRatesTx, posTx, coder.ref(txBuffer));
            end
        end
        
        function releaseImpl(obj) %#ok<MANU>
            if isempty(coder.target)
                % Place simulation termination code here
            else
                % Call C-function implementing device termination
                %coder.ceval('sink_terminate');
            end
        end
    end
    
    methods (Access=protected)
        %% Define input properties
        function num = getNumInputsImpl(~)
            num = 3;
        end
        
        function num = getNumOutputsImpl(~)
            num = 2;
        end
        
        function flag = isInputSizeMutableImpl(~,~)
            flag = false;
        end
        
        function flag = isInputComplexityMutableImpl(~,~)
            flag = false;
        end
        
        function validateInputsImpl(~, eulerAnglesTx,bodyRatesTx,posTx)
            if isempty(coder.target)
                % Run input validation only in Simulation
                validateattributes(eulerAnglesTx,{'single'},{'column'},'','eulerAnglesTx');
                validateattributes(bodyRatesTx,{'single'},{'column'},'','bodyRatesTx');
                validateattributes(posTx,{'int32'},{'column'},'','posTx');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'Wireless Comms Driver';
        end
    end
    
    methods (Static, Access=protected)
        function simMode = getSimulateUsingImpl(~)
            simMode = 'Interpreted execution';
        end
        
        function isVisible = showSimulateUsingImpl
            isVisible = false;
        end
    end
    
    methods (Static)
        function name = getDescriptiveName(~)
            name = 'Communication Driver';
        end
        
        function tf = isSupportedContext(~)
            tf = true;
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src'); %#ok<NASGU>
                addSourceFiles(buildInfo,'Comm_Driver.c',srcDir);

                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);

                STM32includeDir = fullfile(fileparts(mfilename('fullpath')),'sads_balance_cubemx','Core','inc');
                addIncludeFiles(buildInfo,'main.h',STM32includeDir)

                addLinkFlags(buildInfo,'-u _printf_float');
            end
        end
    end
end
