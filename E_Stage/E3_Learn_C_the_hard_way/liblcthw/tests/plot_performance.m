
clc; clear; close all;

%% 1. 实验数据
N = [10, 100, 500, 1000, 5000, 10000];

% 单位：微秒
bubble = [0.393, 18.249, 513.549, ...
          1862.499, 59367.729, 354335.333];

merge = [1.047, 10.519, 79.052, ...
         166.993, 1159.057, 2645.970];

% 转换为毫秒
bubble_ms = bubble / 1000;
merge_ms = merge / 1000;

speedup = bubble ./ merge;

%% 2. 平滑理论曲线
N_dense = logspace(log10(min(N)), log10(max(N)), 500);

% 以 N=1000 为理论基准
ref = find(N == 1000);
N0 = N(ref);

bubble_theory = bubble_ms(ref) .* (N_dense ./ N0).^2;

merge_theory = merge_ms(ref) .* ...
    (N_dense .* log2(N_dense)) ./ (N0 * log2(N0));

speedup_theory = bubble_theory ./ merge_theory;

%% 3. 配色和画布
bubble_color = [0.90, 0.35, 0.28];
merge_color  = [0.12, 0.60, 0.50];
gray_color   = [0.45, 0.45, 0.45];

fig = figure('Color', 'w', ...
    'Position', [100, 100, 1350, 780]);

t = tiledlayout(2, 2, ...
    'TileSpacing', 'compact', ...
    'Padding', 'compact');

%% 4. 左上：冒泡排序
ax1 = nexttile(1);
hold on;

semilogx(N_dense, bubble_theory, '--', ...
    'Color', bubble_color, ...
    'LineWidth', 2.0, ...
    'DisplayName', 'Theory O(n^2)');

semilogx(N, bubble_ms, '-o', ...
    'Color', bubble_color, ...
    'LineWidth', 2.2, ...
    'MarkerSize', 8, ...
    'MarkerFaceColor', bubble_color, ...
    'DisplayName', 'Measured');

title('Bubble Sort', ...
    'FontSize', 15, 'FontWeight', 'bold');
xlabel('Number of Nodes (N)');
ylabel('Average Time (ms)');

xticks(N);
xticklabels(string(N));
xlim([8, 13000]);

ylim([0, max(bubble_ms) * 1.12]);

grid on;
ax1.XMinorGrid = 'on';
ax1.GridAlpha = 0.18;
ax1.Box = 'off';
ax1.FontSize = 11;

legend('Location', 'northwest');
hold off;

%% 5. 左下：归并排序
ax2 = nexttile(3);
hold on;

semilogx(N_dense, merge_theory, '--', ...
    'Color', merge_color, ...
    'LineWidth', 2.0, ...
    'DisplayName', 'Theory O(n log n)');

semilogx(N, merge_ms, '-s', ...
    'Color', merge_color, ...
    'LineWidth', 2.2, ...
    'MarkerSize', 8, ...
    'MarkerFaceColor', merge_color, ...
    'DisplayName', 'Measured');

title('Merge Sort', ...
    'FontSize', 15, 'FontWeight', 'bold');
xlabel('Number of Nodes (N)');
ylabel('Average Time (ms)');

xticks(N);
xticklabels(string(N));
xlim([8, 13000]);

ylim([0, max(merge_ms) * 1.12]);

grid on;
ax2.XMinorGrid = 'on';
ax2.GridAlpha = 0.18;
ax2.Box = 'off';
ax2.FontSize = 11;

legend('Location', 'northwest');
hold off;

%% 6. 右侧：加速比（跨两行）
ax3 = nexttile(2, [2 1]);
hold on;

% 理论加速比
semilogx(N_dense, speedup_theory, '--', ...
    'Color', gray_color, ...
    'LineWidth', 2.0, ...
    'DisplayName', 'Theoretical Trend');

% 实测加速比
semilogx(N, speedup, '-o', ...
    'Color', merge_color, ...
    'LineWidth', 2.5, ...
    'MarkerSize', 9, ...
    'MarkerFaceColor', merge_color, ...
    'DisplayName', 'Measured Speedup');

% 相同性能参考线
yline(1, ':', ...
    'Color', gray_color, ...
    'LineWidth', 1.5, ...
    'DisplayName', 'Equal Performance');

% 标注加速比
for i = 1:length(N)
    text(N(i), speedup(i) + 5, ...
        sprintf('%.2fx', speedup(i)), ...
        'HorizontalAlignment', 'center', ...
        'FontSize', 10, ...
        'FontWeight', 'bold');
end

title('Merge Sort Speedup', ...
    'FontSize', 15, 'FontWeight', 'bold');

xlabel('Number of Nodes (N)');
ylabel('Speedup (Bubble / Merge)');

xticks(N);
xticklabels(string(N));
xlim([8, 13000]);
ylim([0, max(speedup) * 1.18]);

grid on;
ax3.XMinorGrid = 'on';
ax3.GridAlpha = 0.18;
ax3.Box = 'off';
ax3.FontSize = 11;

legend('Location', 'northwest');

hold off;

%% 7. 总标题
title(t, 'Linked List Sorting Performance Analysis', ...
    'FontSize', 18, 'FontWeight', 'bold');

%% 8. 保存结果
exportgraphics(fig, 'sorting_performance.png', ...
    'Resolution', 300);

exportgraphics(fig, 'sorting_performance.pdf', ...
    'ContentType', 'vector');
