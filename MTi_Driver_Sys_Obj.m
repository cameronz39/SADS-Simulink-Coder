classdef MTi_Driver_Sys_Obj < matlab.System & coder.ExternalDependency
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
        function obj = MTi_Driver_Sys_Obj(varargin)
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
                coder.cinclude('MTi_Driver.h');
                coder.ceval('MTi_Driver_Init');
            end
        end
        
        function [g_body, quat, bodyRates, eulerAngles, debug] = stepImpl(obj,bytesIn)  %#ok<INUSD>
            g_body = zeros(3,1,'single');
            quat = zeros(4,1,'single');
            bodyRates = zeros(3,1,'single');
            eulerAngles = zeros(3,1,'single');
            debug = uint16(0);
            if isempty(coder.target)
                % Place simulation output code here 
            else
                % Call C-function implementing device output
               coder.ceval('MTi_Driver_Step',bytesIn,coder.ref(g_body),coder.ref(quat),coder.ref(bodyRates), coder.ref(eulerAngles), coder.ref(debug));
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
            num = 1;
        end
        
        function num = getNumOutputsImpl(~)
            num = 5;
        end
        
        function flag = isInputSizeMutableImpl(~,~)
            flag = false;
        end
        
        function flag = isInputComplexityMutableImpl(~,~)
            flag = false;
        end
        
        function validateInputsImpl(~, bytesIn)
            if isempty(coder.target)
                % Run input validation only in Simulation
                validateattributes(bytesIn,{'uint8'},{'column'},'','bytesIn');
            end
        end
        
        function icon = getIconImpl(~)
            % Define a string as the icon for the System block in Simulink.
            icon = 'MTi Driver';
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
                addSourceFiles(buildInfo,'MTi_Driver.c',srcDir);
                % addSourceFiles(buildInfo,'init_i2c.cpp',srcDir);
                % addSourceFiles(buildInfo,'stm32f4xx_hal_i2c_cameron.c',srcDir);
                % addSourceFiles(buildInfo,'stm32f4xx_hal_i2c_ex_cameron.c',srcDir);
                addSourceFiles(buildInfo,'xbus.c',srcDir);
                % addSourceFiles(buildInfo,'MTi.c',srcDir);

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