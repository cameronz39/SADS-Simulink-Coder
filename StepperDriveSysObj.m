classdef StepperDriveSysObj < matlab.System & coder.ExternalDependency
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
        function obj = StepperDriveSysObj(varargin)
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
                coder.cinclude('StepperDrive.h');
                coder.ceval('StepperDrive_Init');
            end
        end
        
        function stepImpl(obj,desiredPos1,desiredPos2)  %#ok<INUSD>
            
            if isempty(coder.target)
                % Place simulation output code here 
            else
                % Call C-function implementing device output
               coder.ceval('StepperDrive_Step',desiredPos1,desiredPos2);
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
            num = 2;
        end
        
        function num = getNumOutputsImpl(~)
            num = 0;
        end
        
        function flag = isInputSizeMutableImpl(~,~)
            flag = false;
        end
        
        function flag = isInputComplexityMutableImpl(~,~)
            flag = false;
        end
        
        function validateInputsImpl(~, desiredPos1, desiredPos2)
            if isempty(coder.target)
                % Run input validation only in Simulation
                validateattributes(desiredPos1,{'int32'},{'scalar'},'','desiredPos1');
                validateattributes(desiredPos2,{'int32'},{'scalar'},'','desiredPos2');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'Stepper Drive';
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
            name = 'Sink';
        end
        
        function tf = isSupportedContext(~)
            tf = true;
        end
        
        function updateBuildInfo(buildInfo, context)
            if context.isCodeGenTarget('rtw')
                % Update buildInfo
                srcDir = fullfile(fileparts(mfilename('fullpath')),'src'); %#ok<NASGU>
                addSourceFiles(buildInfo,'StepperDrive.cpp',srcDir);
                % addSourceFiles(buildInfo,'init_i2c.cpp',srcDir);
                % addSourceFiles(buildInfo,'stm32f4xx_hal_i2c_cameron.c',srcDir);
                % addSourceFiles(buildInfo,'stm32f4xx_hal_i2c_ex_cameron.c',srcDir);
                % addSourceFiles(buildInfo,'xbus.c',srcDir);

                includeDir = fullfile(fileparts(mfilename('fullpath')),'include');
                addIncludePaths(buildInfo,includeDir);

                STM32includeDir = fullfile(fileparts(mfilename('fullpath')),'sads_balance_cubemx','Core','inc');
                addIncludeFiles(buildInfo,'main.h',STM32includeDir)
                % addIncludeFiles(buildInfo,'stm32f4xx_hal.h',STM32includeDir)
                % addIncludeFiles(buildInfo,'stm32f4xx_hal_def.h',STM32includeDir)

                % CMSISincludeDir = fullfile(fileparts(mfilename('fullpath')),'sads_balance_cubemx','Drivers','CMSIS','Device','ST','STM32F4xx','Include');
                % addIncludeFiles(buildInfo,'stm32f446xx.h',CMSISincludeDir);
                % 
                % LLincludeDir = fullfile(fileparts(mfilename('fullpath')),'sads_balance_cubemx','Drivers','STM32F4xx_HAL_Driver','Inc');
                % addIncludeFiles(buildInfo,'stm32f4xx_ll_i2c.h',LLincludeDir)
                % Use the following API's to add include files, sources and
                % linker flags
                %addLinkFlags(buildInfo,{'-lSource'});
                %addLinkObjects(buildInfo,'sourcelib.a',srcDir);
                %addCompileFlags(buildInfo,{'-D_DEBUG=1'});
                %addDefines(buildInfo,'MY_DEFINE_1')
            end
        end
    end
end
